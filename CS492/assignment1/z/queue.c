#include "queue.h"

//defining the values of the queue variables
int frontOfQueue = 0;
int backOfQueue = -1;
int queueCounter = 0;
int queueSize = 0;

struct product *q;

//creating the queue

//insert a product into the queue
void insertInQueue(struct product p) {

	//if not full
	if(!(queueCounter == queueSize)) {
		//if queue size is only one set the back to -1
		if((queueSize - 1) == backOfQueue) {
			backOfQueue = -1;
		}
		//insert into the back of the queue
		q[++backOfQueue] = p;
		queueCounter++;
	}
}

//remove product from queue and return it
struct product removeFromQueue() {
	
	//create it from the front of the queue
	struct product pRemove = q[frontOfQueue++];
	
	//if there is only one element set the front to 0
	if(frontOfQueue == queueSize)
		frontOfQueue = 0;
	queueCounter--;
	return pRemove;
}



