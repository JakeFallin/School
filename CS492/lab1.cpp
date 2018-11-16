
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;
DEFINE USLEEP = 5;


int main(int argc, char* argv[]) {

	int producerThreads = argv[0];
	int consumerThreads = argv[1];
	int numProducts = argv[2];
	int queueSize = argv[3];
	int schedulingAlgBool = argv[4];
	int quantumVal = argv[5];
	int rngSeed = argv[6];
	queue<int, list<vector>> queue;
	createProducerThread(producerThreads, numProducts, rngSeed);
}

void* createProducerThread(int producerThreads, int numProducts, int rngSeed) {

	int* producerID = new producerID[producerThreads];
	int* timestamp = new timestamp[producerThreads];

	for(int i = 0; i < producerThreads; i++) {
		producerID[i] = myRandom(rngSeed, i);
		timestamp[i] = gettimeofday();
		queue.push(i, producerID[i], timestamp[i]);
		usleep(100000);
	}
	return;

}

int myRandom(int rngSeed, int i) {
	return random(rngSeed*i)%1024;
}