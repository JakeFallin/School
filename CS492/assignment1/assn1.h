#ifndef _ASSN1_H_
#define _ASSN1_H_

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h> 
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <ctype.h>


int main(int argc, char** argv);
void* producer(int*);
void* consumer(int*);
void fibonacci(int);
double getTime(void);
