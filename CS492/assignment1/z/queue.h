#ifndef QUEUE_H_
#define QUEUE_H_

//queue variables
extern int frontOfQueue;
extern int backOfQueue;
extern int queueCounter;
extern int queueSize;


//using this struct we can keep all the products in the queue
extern struct product {
	//in order to work within the queue
	int id;
	//lifetime of the product
	int lifetime;
	//start time
	double timestamp;
	//waiting time
	double starttime;
	//time when it ends
	double endtime; 
};

//creating the queue
extern struct product *q;

//queue methods
void insertInQueue(struct product);
struct product removeFromQueue();

#endif