#include <stdio.h>
// #include <iostream>
#include <unistd.h>

int main() {

	//L3

	// int x=1, y=2;
	// x=fork();
	// y=fork();

	// printf("x=%d y=%d\n",x,y );

	// if(x!=0) printf("1\n");
	// if(y!=0) printf("2\n");

	// if(x>0 || y>0) printf("3\n");
	// if(x==0 && y==0) printf("4\n");
	// if(x!=0 && y!=0) printf("5\n");


	//L4

	// int i = 0;

	// printf("process:%d\n", getpid());


	// (void) fork();

	// printf("process:%d\n", getpid());

	// (void) fork();

	// printf("process:%d\n", getpid());

	// (void) fork();

	// printf("process:%d\n", getpid());


	//q1

	int x=5, y=2;
	int pid;
	x = fork();
	if(x==0){
		printf("!first!\n");
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		pid = getpid();
		printf("I am process: %d\n", pid);
	}
	printf("!middle!\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	y = fork();
	if(y==0){
		printf("!second!\n");
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		pid = getpid();
		printf("I am process: %d\n", pid);
	}
	printf("!end!\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return 0;
}

