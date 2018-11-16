#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct block {

	struct block *head;
	//num of bytes in the block
	int size;
	//check if free
	int flag;
};

void* my_malloc(int num) {
	return sbrk(num);
}

// void* my_malloc(int num) {
// 	struct block* bl = NULL;
// 	if(bl->size >= num) {
// 		bl->head = (struct block*)bl - 1;
// 		bl->free = 1;
// 		bl->size = num;
// 	}
// }

void* my_calloc(int num, int size) {
	int val = num * size;
	void* arr = my_malloc(val);
	memset(arr, 0, val);
	return arr;


	int numset = memtest(arr, 0, val);
}


int main(void)
{
	int test = 5;
	char* str = my_malloc(sizeof(int)*test);
	for(int i = 0; i < test; i++) {
		str[i] = 'hello' + i;
	}
	for(int ii = 0; ii < test; ii++) {
		printf("%d ", str[ii]);
	}
	printf("\n");

	char* str2 = my_calloc(test, sizeof(int));
	for(int j = 0; j < test; j++) {
		str2[j] = 'hello' + j;
	}
	for(int jj = 0; jj < test; jj++) {
		printf("%d ", str2[jj]);
	}
	printf("\n");

	return 0;

} 


// void my_free(void* bl) {	
// 	if(bl->flag == 0) {
// 		bl->head = (struct block*)bl - 1;
// 		bl->flag = 1;
// 	}	
// 	//struct block* b = (struct block_meta*)bl - 1;
// 	//block->head = my_malloc(block->size);
// }
