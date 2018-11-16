#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> 
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#include "helper.h"
#include "queue.h"
//global sleep counter
#define SLEEP 100000

//global values
int numProductsMax, 
    numProductsPro = 0,
    numProductsCon = 0,
    quantumValue = 0,
    seed = 0;

//for measuring performance
double minWait = 1000,
	   maxWait = 0,
	   totalWait = 0,
	   avgWait = 0;

//for measuring performance
double minTurnAroundTime = 1000, 
	   maxTurnAroundTime = 0,
	   totalTurnAroundTime = 0,
	   avgTurnAroundTime = 0;

//pthread variables
pthread_mutex_t mutex;

pthread_cond_t producerCond,
			   consumerCond;


int main(int argc, char** argv) {
	
	//make sure correct number of arguments
	if(argc == 8) {
		
		//take command line arguments
    	int producerThreadsN = atoi(argv[1]);
    	int consumerThreadsN = atoi(argv[2]);
    	int maxProd = atoi(argv[3]);
    	queueSize = atoi(argv[4]);
    	int alg = atoi(argv[5]);
    	quantumValue = atoi(argv[6]);
    	seed = atoi(argv[7]);

    	srandom(seed);

    	//the way this works is if the scheduling algorithm is
    	//first come first serve then then i just set the 
    	//quantum value to a static value greater than what can be
    	//randomized.
    	if(alg == 0) {
    		quantumValue = 1026;
    	}

    	//create threads and ID arrays
    	pthread_t p_thread[producerThreadsN];
    	int pIDs[producerThreadsN];
    	pthread_t c_thread[consumerThreadsN];
    	int cIDs[consumerThreadsN];


    	numProductsMax = maxProd;
    	
    	//so that pthread_create works
    	void* producer();
    	void* consumer();
    	
    	//allocate the queue
		q = malloc(sizeof(struct product)*queueSize);

		//init the pthread variables
		pthread_mutex_init(&mutex, NULL);
    	pthread_cond_init(&producerCond, NULL);
    	pthread_cond_init(&consumerCond, NULL);

		double start = getTime();
		//printf("start time %f\n", start);

		//run the program
		for(int i = 0; i < producerThreadsN; i++) {
			pIDs[i] = i;
			pthread_create(&p_thread[i], NULL, producer, &pIDs[i]);
		}
		for(int i = 0; i < consumerThreadsN; i++) {
			cIDs[i] = i;
			pthread_create(&c_thread[i], NULL, consumer, &cIDs[i]);
		}
		for(int i = 0; i < producerThreadsN; i++) {
			pthread_join(p_thread[i], NULL);
		}		
		double prodTime = getTime();
		for(int i = 0; i < consumerThreadsN; i++) {
			pthread_join(c_thread[i], NULL);
		}		

		//runtime stuff
		double end = getTime();

		printf("\n[][][][][]Experimentation Metrics[][][][][]\n");

		printf("Total Runtime %f ms\n", (end-start));

		avgTurnAroundTime = totalTurnAroundTime/numProductsMax;
		printf("minTurn: %f, maxTurn: %f, avgTurn: %f\n", 
			minTurnAroundTime, maxTurnAroundTime, avgTurnAroundTime);

		avgWait = totalWait/numProductsMax;
		printf("minWait: %f, maxWait: %f, avgWait: %f\n", 
			minWait, maxWait, avgWait);

		double help1 = prodTime - start;
		double prodT = numProductsMax/(help1/6000);
		printf("Producer Throughput: %f\n", prodT);

		double help2 = end - start;
		double consT = numProductsMax/(help2/6000);
		printf("Consumer Throughput: %f\n", consT);

		free(q);
		return 1;

	} else {
		printf("Please supply the correct number of arguments\n");
		return 1;
	}
}


//producer
void *producer(int *id) {

	//printf("Thread Producing with id of %d\n", *id);

	////there needs to be available products in order to do anything
	while(numProductsMax > numProductsPro) {

		pthread_mutex_lock(&mutex);
		////wait while the queue is full
		while((numProductsMax > numProductsPro) && (queueCounter >= queueSize)) {
			pthread_cond_wait(&producerCond, &mutex);
		}
		//now add a new product to the queue
		if(numProductsMax > numProductsPro) {
			struct product pro;
			pro.id = numProductsPro;
			pro.lifetime = random()%1024;
			pro.timestamp = getTime();
			pro.starttime = 0;
			pro.endtime = getTime();
			numProductsPro++;
			insertInQueue(pro);
			
			//printf("Product created with id of %d\n", pro.id);
		}
		//now we want to setup the consuming
		pthread_cond_broadcast(&consumerCond);
		pthread_mutex_unlock(&mutex);
		usleep(10000);
	}
	pthread_exit(0);
}

//consumer 
//two cases first come first serve and round robin
void *consumer(int *id) {

	//printf("Thead Consuming with id of %d\n", *id);
	//create a product here and some metrics so we can get results in main
	struct product pro;
	double timeSoFar = 0;
	double timeTillEnd = 0;
	double turnAroundTime = 0;
	int loop = 0;
	
	//same thing-- while there is available products do the consuming
	while(numProductsMax > numProductsCon) {
			//printf("\nprogress\n");

		pthread_mutex_lock(&mutex);
		//wait while the queue is full
		while((numProductsMax > numProductsPro) && (queueCounter < queueSize)) {
			
			pthread_cond_wait(&consumerCond, &mutex);
		}
		//we want to dequeue a product and start the consuming
		if(queueCounter != 0) {
			timeSoFar = getTime();
			pro = removeFromQueue();
		}

		//if its still the case then we can start
		if(numProductsMax > numProductsCon) {
			//printf("\nworking\n");

			//Round Robin
			//this checks to see if the quantum value is less than the lifetime
			//which is capped at 1024, if so then we know its RR
			if(pro.lifetime > quantumValue) {
				//printf("\nround robin\n");
				pro.lifetime = pro.lifetime - quantumValue;
				//run the fibonacci 10 times
				for(loop = quantumValue; loop > 0; loop--) {
					fibonacci(10);
				}
				timeTillEnd = getTime();
				//calculate the times so we can store it in the product
				pro.starttime += timeSoFar;
				pro.starttime -= pro.endtime;
				pro.endtime = timeTillEnd;
				insertInQueue(pro);
			//first come first serve	
			} else {
				//printf("\nfirst come first serve\n");
				loop = pro.lifetime;
				//run fibonacci
				for(loop = pro.lifetime; loop > 0; loop--) {
					fibonacci(10);
				}
				//calculate the running time so we can store it in the product
				//we know that it has been consumed here
				numProductsCon++;
				timeTillEnd = getTime();
				pro.starttime += timeSoFar;
				pro.starttime -= pro.endtime;
				turnAroundTime = timeTillEnd - pro.timestamp;


				//we must now do all of these checks to update the waiting and turnaround times
				if(pro.starttime > maxWait) {
					maxWait = pro.starttime;
				}
				if(pro.starttime < minWait) {
					minWait = pro.starttime;
				}
				if(turnAroundTime > maxTurnAroundTime) {
					maxTurnAroundTime = turnAroundTime;
				}
				if(turnAroundTime < minTurnAroundTime) {
					minTurnAroundTime = turnAroundTime;
				}
				totalWait += pro.starttime;
				totalTurnAroundTime += turnAroundTime;

				//printf("Consumer %d has consumed Product %d.  Wait Time: %f milliseconds, Turnaround Time: %f\n", *id,pro.id, pro.starttime, turnAroundTime);

			}
		}
		//broadcast and unlock
		pthread_cond_broadcast(&producerCond);
		pthread_mutex_unlock(&mutex);
		usleep(10000);
	}
	pthread_exit(0);
}



