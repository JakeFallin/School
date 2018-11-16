#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void child(int);
void parent(int);
void victoryC(int);
void victoryP(int);
int childCount = 0;
int parentCount = 0;
pid_t pid;

int main(void) {

	srand(123456789);
	pid = getpid();
 	pid_t pidd; 


    signal(SIGINT, parent);

    if((pid = fork()) == 0)
    {
    	 while(1){}	
    	
    } else {
		usleep(2000000);
    	kill(pidd, SIGINT); 
		signal(SIGINT, child);

    }
    return 0;
}

void child(int pid) {

	 	printf("PING");

	 childCount++;
	 printf("\nCHILDCOUNT:%d\n", childCount);
	int num = rand() % (100);

	
	if(num > 90) {
		printf("MISSED");
		signal(SIGTSTP, victoryP);

	} else { 
 	printf("\nMyNumC:%d\n", num);
 	printf("\nMyPID:%d\n", pid);

 	kill(pid, SIGINT);
 	signal(SIGINT, parent);
	}

 	// if(num < 90) {
 	// 	kill(pid , SIGINT);
 	// }
}


void parent(int pid) {

	 printf("PONG");
	parentCount++;
	 printf("\nPARENTCOUNT:%d\n", parentCount);
	int num = rand() % (100);

	if(num > 90) {
		printf("MISSED PARENT");
				signal(SIGTSTP, victoryC);

	} else {
 	printf("\nMyNumP:%d\n", num);
 	printf("\nMyPID:%d\n", pid);

 	kill(pid, SIGINT);
 	signal(SIGINT, child);
 }

 	// if(num < 90) {
 	// 	kill(pid , SIGINT);
 	// }
}

void victoryC(int pid) {

	printf("VICTORY for Child!");
	exit(1);
}

void victoryP(int pid) {

	printf("VICTORY for Parent!");
	exit(1);
}





 