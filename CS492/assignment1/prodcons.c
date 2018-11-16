#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> 
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>


#include "prodcons.h"

//producer

void *producer(int *id) {

	printf("Thread Producing with id of %d\n", *id);

	while(numProductsMax > numProductsPro) {

		pthread_mutex_lock(&mutex);
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
			
			printf("Product created with id of %d\n", pro.id);
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

	printf("Thead Consuming with id of %d\n", *id);
	struct product pro;
	double timeSoFar = 0;
	double timeTillEnd = 0;
	double turnAroundTime = 0;
	int loop = 0;
	
	while(numProductsMax > numProductsCon) {
			//printf("\nprogress\n");

		pthread_mutex_lock(&mutex);
		while((numProductsMax > numProductsPro) && (queueCounter < queueSize)) {
			
			pthread_cond_wait(&consumerCond, &mutex);
		}
		//now remove a new product to the queue
		if(queueCounter != 0) {
			timeSoFar = getTime();
			pro = removeFromQueue();
		}

		if(numProductsCon < numProductsMax) {
			//printf("\nworking\n");

			//Round Robin
			if(pro.lifetime > quantumValue) {
				//printf("\nround robin\n");
				pro.lifetime = pro.lifetime - quantumValue;

				for(loop = quantumValue; loop > 0; loop--) {
					fibonacci(10);
				}
				timeTillEnd = getTime();
				pro.starttime = pro.starttime + timeSoFar - pro.endtime;
				pro.endtime = timeTillEnd;
				insertInQueue(pro);
			} else {
				//printf("\nfirst come first serve\n");
				loop = pro.lifetime;
				for(loop = pro.lifetime; loop > 0; loop--) {
					fibonacci(10);
				}
				numProductsCon++;
				timeTillEnd = getTime();
				pro.starttime = pro.starttime + timeSoFar - pro.endtime;
				turnAroundTime = timeTillEnd - pro.timestamp;

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

				printf("Consumer %d has consumed Product %d.  Wait Time: %f milliseconds, Turnaround Time: %f\n", *id,pro.id, pro.starttime, turnAroundTime);

			}
		}
		//broadcast and unlock
		pthread_cond_broadcast(&producerCond);
		pthread_mutex_unlock(&mutex);
		usleep(10000);
	}
	pthread_exit(0);
}