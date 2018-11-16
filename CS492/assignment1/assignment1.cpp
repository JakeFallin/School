
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <float.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

#define SLEEP 100000

typedef struct {
    int productID;
    int timelimit;
    struct timeval timestamp;
    struct timeval timestart;
    double waittimeMS;
} produce;

typedef struct {
    int ID;
    void* consumerPointer;
} consumerHelp;


double consumerBegin = 0, 
	   consumerEnd = 0;
double producerBegin = 0, 
	   producerEnd = 0;

double turnAroundMin = DBL_MAX, 
	   turnAroundMax = DBL_MIN;

double turnAround = 0,
	   turnAroundWait = 0;

double minWait = DBL_MAX,
	   maxWait = DBL_MIN;

int numProducts = 0, 
    numProductsP = 0,
    numProductsC = 0,
    productID = 0,
    quantumValue = 0,
    queueCounter = 0;

std::queue<produce> q;

pthread_mutex_t producerMutex, 
				consumerMutex, 
				productMutex, 
				queueMutex;

pthread_cond_t fullCondition,
			   emptyCondition;



double getTime() {
	struct timeval time;
	gettimeofday(&time, NULL);
	double t = time.tv_sec + ((double) time.tv_usec) * 1000000;
	return t; 
}
double elapsedSeconds(timeval &tm1, timeval &tm2) {
	double t2 = tm2.tv_sec + ((double) tm2.tv_usec) *  1000000;
	double t1 = tm1.tv_sec + ((double) tm1.tv_usec) *  1000000;
	return t2-t1;
}


int fibbonaci(int fibNum) {
	if(fibNum == 1) {
		return fibNum;
	} else {
		return fibbonaci(fibNum - 1) + fibbonaci(fibNum - 2);
	}
}

void fibbonaciHelper(int fib, int num) {
	for(int i = 0; i < num; i++) {
		fibbonaci(fib);
	}
}

void* producer(void* p) {
	int* producerInt = (int*) p;

	while(1) {

		pthread_mutex_lock(&producerMutex);
		if(numProductsP == numProducts) {
			pthread_mutex_unlock(&producerMutex);
			producerEnd = getTime();
			pthread_exit(0);
		}
		numProductsP++;
		pthread_mutex_unlock(&producerMutex);

		produce pro = produce();

		pthread_mutex_lock(&productMutex);
		pro.productID = productID++;
		pthread_mutex_unlock(&productMutex);

		pthread_mutex_lock(&queueMutex);
		if(queueCounter == 0) {
			while(queueCounter == q.size()) {
				pthread_cond_wait(&fullCondition, &queueMutex);
			}
		}

		struct timeval time;
		gettimeofday(&time, NULL);
		pro.timelimit = random() % 1024;
		pro.timestamp = time;
		pro.timestamp = time;
		q.push(pro);

		pthread_cond_signal(&emptyCondition);
		pthread_mutex_unlock(&queueMutex);

		usleep(SLEEP);
		
		//fprintf(stdout, Producer %d has produced product %dn, id, p.productId);
	}
}

void* consumer(void* c) {

	consumerHelp consumerhelp;
	consumerhelp.consumerPointer = *((int*)c);

	while(1) {

		pthread_mutex_lock(&consumerMutex);

		if(numProducts == numProductsC) {
			consumerEnd = getTime();
			pthread_mutex_unlock(&consumerMutex);
			pthread_exit(0);
		}

		consumerhelp.consumerPointer = &consumerhelp.ID;
		pthread_mutex_unlock(&consumerMutex);

		usleep(SLEEP);

	}
}

void consumerFirstCome() {

	pthread_mutex_lock(&queueMutex);
	while(q.empty()) {
		pthread_cond_wait(&emptyCondition, &queueMutex);
	}

	produce pro = q.front();
	q.pop();

	struct timeval waitTime;
	gettimeofday(&waitTime, NULL);
	double sec = elapsedSeconds(pro.timestart, waitTime);
	pro.waittimeMS = sec;
	pthread_cond_signal(&fullCondition);
	pthread_mutex_unlock(&queueMutex);

	fibbonaciHelper(pro.timelimit, 10);

	struct timeval waitTime3;
	gettimeofday(&waitTime3, NULL);
	double sec2 = elapsedSeconds(pro.timestamp, waitTime3);
	turnAround += sec2;
	if(turnAround > turnAroundMax) {
		turnAroundMax = turnAround; 
	} else if(turnAround < turnAroundMin) {
		turnAroundMin = turnAround;
	}
		
	turnAroundWait += pro.waittimeMS;
	if(pro.waittimeMS > maxWait) {
		turnAroundMax = pro.waittimeMS; 
	} else if(pro.waittimeMS < minWait) {
		turnAroundMin = pro.waittimeMS;
	}

	//printf(Consumer %d has consumed product %dn, id, p.productId);
    //fflush(stdout);

    numProductsC++;

}

void consumerRoundRobin() {

	pthread_mutex_lock(&queueMutex);
	while(q.empty()) {
		pthread_cond_wait(&emptyCondition, &queueMutex);
	}

	produce pro = q.front();
	q.pop();

	struct timeval waitTime;
	gettimeofday(&waitTime, NULL);
	double sec = elapsedSeconds(pro.timestart, waitTime);
	pro.waittimeMS = sec;

	if(pro.timelimit == quantumValue) {

		pro.timelimit -= quantumValue;
		fibbonaciHelper(quantumValue, 10);

		struct timeval waitTime2;
		gettimeofday(&waitTime2, NULL);
		pro.timestart = waitTime2;

		q.push(pro);
		pthread_mutex_unlock(&queueMutex);
	} else {

		pthread_cond_signal(&fullCondition);
		pthread_mutex_unlock(&queueMutex);

		fibbonaciHelper(pro.timelimit, 10);

		struct timeval waitTime3;
		gettimeofday(&waitTime3, NULL);
		double sec2 = elapsedSeconds(pro.timestamp, waitTime3);
		turnAround += sec2;
		if(turnAround > turnAroundMax) {
			turnAroundMax = turnAround; 
		} else if(turnAround < turnAroundMin) {
			turnAroundMin = turnAround;
		}
		
		turnAroundWait += pro.waittimeMS;
		if(pro.waittimeMS > maxWait) {
			turnAroundMax = pro.waittimeMS; 
		} else if(pro.waittimeMS < minWait) {
			turnAroundMin = pro.waittimeMS;
		}

		//change
		//printf(Consumer %d has consumed product %dn, id, p.productId);
        fflush(stdout);

        numProductsC++;

	}
}

int main(int argc, char** argv) {

	int producerThreadsN, consumerThreadsN, seed, alg;

	if(argc == 8) {

		pthread_mutex_init(&producerMutex, NULL);
    	pthread_mutex_init(&consumerMutex, NULL);
    	pthread_mutex_init(&queueMutex, NULL);
    	pthread_mutex_init(&productMutex, NULL);
    	pthread_cond_init(&fullCondition, NULL);
    	pthread_cond_init(&emptyCondition, NULL);

    	producerThreadsN = atoi(argv[0]);
    	consumerThreadsN = atoi(argv[1]);
    	numProducts = atoi(argv[2]);
    	queueCounter = atoi(argv[3]);
    	alg = atoi(argv[4]);
    	quantumValue = atoi(argv[5]);
    	seed = atoi(argv[6]);

    	srandom(seed);

    	 printf("\ntest\n");


    	consumerHelp* consumerhelp = new consumerHelp[consumerThreadsN];

    	struct timeval start, end;
    	gettimeofday(&start, NULL);

    	pthread_t* producerThreads = new pthread_t[numProductsP];
    	pthread_t* consumerThreads = new pthread_t[numProductsC];

    	//need to finish main testing
    	//
    	//
    	//
    	producerBegin = getTime();

    	for(int i = 0; i < producerThreadsN; i++) {
    		int res = pthread_create(&producerThreads[i], NULL, producer, new int(i+1));
    		if (res != 0) {
            	printf("stderr, Unable to create producer threads, there was an error\n");
            	exit(1);
        	}
    	}

    	consumerBegin = getTime();
   //  	for(int i = 0; i < consumerThreadsN; i++) {

   //  		consumerhelp[i] = consumerHelp();
   //  		consumerhelp[i].ID = i+1;
   //  		if(alg == 0) {
   //  			consumerhelp[i].consumerPointer = &consumerFirstCome;
   //  		} else if(alg == 1) {
			// 	consumerhelp[i].consumerPointer = &consumerRoundRobin;
   //  		}
 		// 	else {
   //          	printf("stderr, Unknown scheduling algorithm type %d, exiting\n", alg);
   //          	return -1;
   //      	}
			// int res = pthread_create(&consumerThreads[i], NULL, consumer, &consumerhelp[i]);
   //  		if (res != 0) {
   //          	printf("stderr, Unable to create producer threads, there was an error\n");
   //          	exit(1);
   //      	}
   //  	}


    	for(int i = 0; i < producerThreadsN; i++) {
    		int res = pthread_join(producerThreads[i], NULL);
    		if (res != 0) {
            	printf("stderr, Unable to create producer threads, there was an error\n");
            	exit(1);
        	}    	
    	}


		for(int i = 0; i < consumerThreadsN; i++) {
    		int res = pthread_join(consumerThreads[i], NULL);
    		if (res != 0) {
            	printf("stderr, Unable to create consumer threads, there was an error\n");
            	exit(1);
        	}    	
    	}

    	gettimeofday(&end, NULL);


    	 printf("\nTotal time %fs\n", elapsedSeconds(start, end));
	    printf("Min turn-around %fs, max turn-around %fs, average turn-around %fs\n", turnAroundMin, turnAroundMax, ((double) turnAround) / numProducts);
	    printf("Min wait %fs, max wait %fs, average wait %fs\n", minWait , maxWait, turnAroundWait,  numProducts);

	    printf("Total time produce %fs, total time consume %fs\n", (producerEnd - producerBegin), (consumerEnd - consumerBegin));
	    printf("Producer throughput %f productsmin\n", ((double) numProductsP) *  ((producerEnd - producerBegin) / 60));
	    printf("Consumer throughput %f productsmin\n", ((double) numProductsC) * ((consumerEnd - consumerBegin) / 60));


    	pthread_mutex_destroy(&producerMutex);
    	pthread_mutex_destroy(&consumerMutex);
    	pthread_mutex_destroy(&queueMutex);
    	pthread_mutex_destroy(&productMutex);

    	pthread_cond_destroy(&fullCondition);
    	pthread_cond_destroy(&emptyCondition);


    	return 0;

	}

}




