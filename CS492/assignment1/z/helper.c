#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//get current time with timeval
double getTime(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	//calculate the time in MS
	double time = ((tv.tv_sec) * 1000) + ((tv.tv_usec) / 1000);
	return time;
}

//iterative fibbonaci algorithm
void fibonacci(int num) {
	int x = 0, y = 1, z = 1;
	for(int i = 0; i < num; i++) {
		x = y;
		y = z;
		z = x + y;
	}
}