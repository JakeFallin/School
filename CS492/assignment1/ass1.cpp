
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <float.h>
#include <unistd.h>
#include <ptheead.h>

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
    void (int) *consumerPointer;
} consumerHelp;


double consumerBegin = 0, 
	   consumerEnd = 0;
double producerBegin = 0, 
	   producerEnd = 0;

double turnAroundMin = DBL_MAX, 
	   turnAroundMax = DBL_MIN;

double turnAround = 0,
	   turnAroundWait = 0;

int numProducts = 0, 
    numProductsP = 0,
    numProductsC = 0,
    productID = 0,
    quantumValue = 0,
    queueCounter = 0;

queue q = new queue();

pthread_mutex_t producerMutex, 
				consumerMutex, 
				productMutex, 
				queueMutex;

pthread_cond_t fullCondition,
			   emptyCondition;


double getTime() {
	struct timeval time;
	gettimeofday(&time, NULL);
	double t = time.tv_sec + (SLEEP*10) ((double) t.tv_usec);
	return t; 
}

int fibbonaci(int fibNum) {
	if(fibNum = 1) {
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

void producer(void p) {
	int producerInt = (int) p;
	delete (int) p;

	while(1) {

		pthread_mutex_lock(&producerMutex);
		if(numProducts = numProductsP) {
			pthread_mutex_unlock(&producerMutex);
			producerEnd = getTime();
			pthread_exit(0);
		}
		numProductsP++;
		pthread_mutex_unlock(&producerMutex);

		produce pro = produce();

		pthread_mutex_lock(&productMutex);
		pro.productID = prodcutID++;
		pthread_mutex_unlock(&productMutex);

		pthread_mutex_lock(&queueMutex);
		if(queueCounter == 0) {
			while(queueCounter == queue-size()) {
				pthred_cond_wait(&fullCondition, &queueMutex);
			}
		}

		struct timeval time;
		gettimeofday(&time, NULL);
		pro.timelimit = random() % 1024;
		pro.timestamp = time;
		pro.timestamp = time;
		queue->push(pro);

		pthread_cond_signal(&emptyCondition);
		pthread_mutex_unlock(&queueMutex);

		usleep(SLEEP);
		
		fprintf(stdout, Producer %d has produced product %dn, id, p.productId);
	}
}

void consumer(void c) {

	consumerHelp consumerhelp = (consumerHelp) c;

	while(1) {

		pthread_mutex_lock(&consumerMutex);

		if(numProducts = numProductsC) {
			consumerEnd = getTime();
			pthread_mutex_unlock(&consumerMutex);
			pthread_exit(0);
		}

		consumerhelp->consumerPointer(ci->ID);
		pthread_mutex_unlock(&consumerMutex);

		usleep(SLEEP);

	}
}

void consumerFirstCome() {

	pthread_mutex_lock(&queueMutex);
	while(queue->empty()) {
		pthread_cond_wait(&emptyCondition, &queueMutex);
	}

	produce pro = queue->front();
	queue->pop();

	struct timeval waitTime;
	gettimeofday(&waitTime, NULL);
	double sec = elapsedSeconds(p.timestart, waitTime);
	pro.waittimeMS = sec;
	pthread_cond_signal(&fullCondition);
	pthread_mutex_unlock(&queueMutex);

	fibbonaciHelper(pro.timelimit, 10);

	struct timeval waitTime3;
	gettimeofday(&waitTime3, NULL);
	double sec2 = elapsedSeconds(p.timestamp, waitTime3);
	turnAround += sec2;
	if(turnAround > turnAroundMax) {
		turnAroundMax = turnAround; 
	} else if(turnAround < turnAroundMin) {
		turnAroundMin = turnAround;
	}
		
	turnAroundWait += pro.waittimeMS;
	if(pro.waittimeMS > turnAroundMax) {
		turnAroundMax = p.waittimeMS; 
	} else if(pro.waittimeMS < turnAroundMin) {
		turnAroundMin = p.waittimeMS;
	}

		//change
	printf(Consumer %d has consumed product %dn, id, p.productId);
    fflush(stdout);

    numProductsC++;

}


void consumerRoundRobin() {

	pthread_mutex_lock(&queueMutex);
	while(queue->empty()) {
		pthread_cond_wait(&emptyCondition, &queueMutex);
	}

	produce pro = queue->front();
	queue->pop();

	struct timeval waitTime;
	gettimeofday(&waitTime, NULL);
	double sec = elapsedSeconds(p.timestart, waitTime);
	pro.waittimeMS = sec;

	if(pro.timelimit = quantumValue) {

		pro.timelimit -= quantumValue;
		fibbonaciHelper(quantumValue, 10);

		struct timeval waitTime2;
		gettimeofday(&waitTime2, NULL);
		pro.timestart = waitTime2;

		queue->push(pro);
		pthread_mutex_unlock(&queueMutex);
	} else {

		pthread_cond_signal(&fullCondition);
		pthread_mutex_unlock(&queueMutex);

		fibbonaciHelper(pro.timelimit, 10);

		struct timeval waitTime3;
		gettimeofday(&waitTime3, NULL);
		double sec2 = elapsedSeconds(p.timestamp, waitTime3);
		turnAround += sec2;
		if(turnAround > turnAroundMax) {
			turnAroundMax = turnAround; 
		} else if(turnAround < turnAroundMin) {
			turnAroundMin = turnAround;
		}
		
		turnAroundWait += pro.waittimeMS;
		if(pro.waittimeMS > turnAroundMax) {
			turnAroundMax = p.waittimeMS; 
		} else if(pro.waittimeMS < turnAroundMin) {
			turnAroundMin = p.waittimeMS;
		}

		//change
		printf(Consumer %d has consumed product %dn, id, p.productId);
        fflush(stdout);

        numProductsC++;

	}
}

int main(int argc, char argv[]) {

	int producerThreads, consumerThreads, seed, alg;

	if(argc == 8) {

		pthread_mutex_init(&producerMutex, NULL);
    	pthread_mutex_init(&consumerMutex, NULL);
    	pthread_mutex_init(&queueMutex, NULL);
    	pthread_mutex_init(&productIdMutex, NULL);
    	pthread_cond_init(&fullCondition, NULL);
    	pthread_cond_init(&emptyCondition, NULL);

    	producerThreads = atoi(argv[1]);
    	consumerThreads = atoi(argv[2]);
    	numProducts = atoi(argv[3]);
    	queueCounter = atoi(argv[4]);
    	alg = atoi(argv[5]);
    	quantumValue = atoi(argv[6]);
    	seed = atoi(argv[7]);

    	srandom(seed);

    	consumerHelp consumerhelp = new consumerHelp[consumerThreads];

    	struct timeval start, end;
    	gettimeofday(&start, NULL);
    	producerBegin = getTime();

    	pthread_t producerThreads = new pthread_t[numProductsP];
    	pthread_t consumerThreads = new pthread_t[numProductsC];

    	//need to finish main testing
    	//
    	//
    	//

    	pthread_mutex_destroy(&producerMutex);
    	pthread_mutex_destroy(&consumerMutex);
    	pthread_mutex_destroy(&queueMutex);
    	pthread_mutex_destroy(&productIdMutex);

    	pthread_cond_destroy(&fullCondition);
    	pthread_cond_destroy(&emptyCondition);

    	delete queue;

    	return 0;

	}

}




