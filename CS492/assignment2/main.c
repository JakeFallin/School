#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MEM 512

char* my_plist;
char* my_ptrace;
int sizeOfPages;
int algorithm;
int prepaging;
int pageCounter;
int pageID;
int programCounter;

int pageSize;
int processesPerPage;

typedef struct {
	int validBit:1;
	//CLOCK
	int accessed:1;
	//LRU
	struct timespec lastTimeAccessed;
} pageT;

typedef struct {
	int pid;
	int startTime;
	int endTime;
	int flag;
} proc;

pageT* pageTableArr;
proc* processArr;


int cmp_timespec(struct timespec a, struct timespec b) {
    if (a.tv_sec < b.tv_sec)
        return -1;
    else if (a.tv_sec > b.tv_sec)
        return 1;
    else if (a.tv_nsec < b.tv_nsec)
        return -1;
    else if (a.tv_nsec > b.tv_nsec)
        return 1;
    else
        return 1;
}


void pageWork(int pid, int pageNum, int algorithm) {

	int startTime = processArr[pid].startTime;
	int endTime = processArr[pid].endTime;
	assert(startTime <= pageNum && pageNum < endTime);

	int swapNum = -1;
	//fprintf(stderr, "start:%d\t end:%d\n", startTime, endTime);
	for(int i = startTime; i < endTime; ++i) 
		if(pageTableArr[i].validBit) {
			swapNum = i;
			break;
		}
	

	assert(swapNum != -1);

	if(algorithm == 3) {
		int flag = processArr[pid].flag;
		assert(0 <= flag && flag < (endTime - startTime));
		for(int i = flag; ; ++i) { 

			int bit = (i % (endTime - startTime)) + startTime;
			if(pageTableArr[bit].validBit == 1) {
				if(pageTableArr[bit].accessed == 1) {
					pageTableArr[bit].accessed = 0;
				} else {
					flag = bit;
					break;
				}
			}
		}
		swapNum = flag;
		processArr[pid].flag = (flag+1) % (endTime - startTime);
	} else if(algorithm == 1 || algorithm == 2) {

		for(int i = startTime; i < endTime; ++i) {
			if(pageTableArr[i].validBit && cmp_timespec(pageTableArr[swapNum].lastTimeAccessed, pageTableArr[swapNum].lastTimeAccessed)>0) {
				swapNum = i;
			}
		}
	}

	assert(startTime <= swapNum && swapNum < endTime);
	pageTableArr[swapNum].validBit = 0;
	pageTableArr[pageNum].validBit = 1;

	if(algorithm == 3) {
		pageTableArr[pageNum].accessed = 1;
	} else {
		if(clock_gettime(CLOCK_MONOTONIC, &pageTableArr[pageNum].lastTimeAccessed) < 0) {
			printf("Clock Error");
			exit(1);
		}
	}
	//printf("[%d] replacing page %d for %d\n", pid, swapNum, pageNum);

}

int main(int argc, char* argv[]) {

	if(argc == 6) {

		//pagesize
		sizeOfPages = atoi(argv[3]);

		//algorithm 
		//FIFO 		= 1
		//LRU 		= 2
		//CLOCK 	= 3
		if(strncmp("FIFO", argv[4], 4) == 0) {
			algorithm = 1; 
		} else if(strncmp("LRU", argv[4], 3) == 0) {
			algorithm = 2;
		} else if(strncmp("CLOCK", argv[4], 5) == 0) {
			algorithm = 3;
		} else {
			printf("Incorrect algorithm. Exiting.");
			return 1;
		}

		//prepaging
		// (-)	 = 0
		// (+) 	 = 1
		if(strncmp("-", argv[5], 1) == 0) {
			prepaging = 0;
		} else if(strncmp("+", argv[5], 1) == 0) {
			prepaging = 1;
		} else {
			printf("Incorrect prepaging symbol. Exiting");
			return 1;
		}

		pageSize = 0;
		processesPerPage = 0;
		

		//read plist.txt
		FILE* pl;
		pl = fopen(argv[1], "r");
		int rd, pid, address;

		while((rd = fscanf(pl, "%d %d\n", &pid, &address)) != EOF) {
			int temp = (int)ceil((double)address/sizeOfPages);
			//printf("TEMP: %d\n", temp);
			pageSize += temp;
			processesPerPage++;
		}

		// pageTableArr = malloc(pageSize * sizeof(pageT));
		// processArr = malloc(processesPerPage * sizeof(proc));

		// for(int i = 0; i < pageSize; i++) {
		// 	pageTableArr[i].validBit = 0;
		// 	pageTableArr[i].accessed = 0;
		// 	pageTableArr[i].lastTimeAccessed.tv_sec = 0;
		// 	pageTableArr[i].lastTimeAccessed.tv_nsec = 0;
		// }
		// for(int i = 0; i < processesPerPage; i++) {
		// 	processArr[i].pid = 0;
		// 	processArr[i].startTime = 0;
		// 	processArr[i].endTime = 0;
		// 	processArr[i].flag = 0;
		// }

		pageTableArr = calloc(pageSize, sizeof(pageT));
    	processArr = calloc(processesPerPage, sizeof(proc));

		if(fseek(pl, 0L, SEEK_SET) != 0) {
			printf("Error restarting stream\n");
		} else {
			int prCounter = 0, paCounter = 0;
			while((rd = fscanf(pl, "%d %d\n", &pid, &address)) != EOF) {
				int temp = (int)ceil((double)address/sizeOfPages);
				processArr[prCounter].pid = pid;
				processArr[prCounter].startTime = paCounter;
				processArr[prCounter].endTime =paCounter + temp;
				processArr[prCounter].flag = 0;
			
			paCounter += temp;
			++prCounter;
		}
	}

		// for (int i = 0; i < processesPerPage; ++i) {
  //       printf("pid = %d has pages %d..%d\n",
  //               processArr[i].pid,
  //               processArr[i].startTime,
  //               processArr[i].endTime-1);
  //   	}

		fclose(pl);

		for(int i = 0; i < processesPerPage; ++i) {

			//printf("alloc for proc %d\n", i);

			int ppp = MEM / sizeOfPages / processesPerPage;
			int startTime = processArr[i].startTime;
			int endTime = MIN(processArr[i].endTime, startTime + ppp);
			for(int j = startTime; j < endTime; ++j) {
				pageTableArr[j].validBit = 1;
				if(algorithm == 3) {
					pageTableArr[j].accessed = 1;
				} else if(algorithm == 1) {
					if(clock_gettime(CLOCK_MONOTONIC, &pageTableArr[j].lastTimeAccessed) < 0) {
						printf("Clock Error");
						exit(1);
					}
				}
				//printf("\tloading page %d\n", j);
			}
		}

		{ // checks
        int bytes_in_mem = 0;
        for (int i = 0; i < pageSize; ++i)
            if (pageTableArr[i].validBit)
                bytes_in_mem += sizeOfPages;
        assert(bytes_in_mem <= 512);
    	}

		FILE* pt;
		pt = fopen(argv[2], "r");

		int numSwaps = 0;
		int memoryAddress;

		while((rd = fscanf(pt, "%d %d", &pid, &memoryAddress)) != EOF) {
			int startTime = processArr[pid].startTime;
			int endTime = processArr[pid].endTime;
			memoryAddress--;
			int page = startTime + (memoryAddress/sizeOfPages);
			//fprintf(stderr, "startTime: %d\t endtime: %d\t page: %d\n", startTime, endTime, page);
			//fprintf(stderr,"p%d needs mem[%d], page = %d (should be in %d..%d)\n\n", pid, memoryAddress, page, startTime, endTime);
        	
        	assert(startTime <= page && page < endTime);


			if(!pageTableArr[page].validBit) {

           //fprintf(stderr, "swap:%d\t pid:%d\n",numSwaps, pid);

				numSwaps++;
				pageWork(pid, page, algorithm);

				if(prepaging) {
					int isPage = 0;
					for(int i = (page+1); i < endTime; i++) {
						if(!pageTableArr[i].validBit) {
							pageWork(pid, i, algorithm);
							isPage = 1;
							break;
						}
					}
					if(!isPage) {
						for(int i = startTime; i < page; ++i) {
							if(!pageTableArr[i].validBit) {
								pageWork(pid, i, algorithm);
								break;
							}
						}
					}
				} else {
					if(algorithm == 3) {
						pageTableArr[page].accessed = 1;
					} else if(algorithm == 2) {
						if(clock_gettime(CLOCK_MONOTONIC, &pageTableArr[page].lastTimeAccessed) < 0) {
							printf("Time Error");
							return 1;
						}
					}
				}
			}
		}

	fclose(pt);

	free(pageTableArr);
	free(processArr);

	printf("Swap Count: %d\n", numSwaps);

	} else {
		printf("please supply the correct arguments.");
		return 1;
	}
}