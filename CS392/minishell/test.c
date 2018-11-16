#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
	int num = atoi(argv[1]);
	for(int i = 0; i < num; i++) {
		printf("Test script\n");
		sleep(1);
	}

	return 0;
}