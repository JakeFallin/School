#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct *void block {

	void *block next;
	//num of bytes in the block
	int size;
	//check if free
	int flag;
}

int main(void)
{
	printf("malloc: %d\n", malloc(3));
	printf("calloc: %d\n", calloc(3, 5));

} 

void* my_malloc(int num) {
	return sbrk(num);
}

void* my_calloc(int num, int size) {
	int val = num * size;
	void* arr = sbrk(val);
	memset(arr, 0, sizeof(int)*val);
}

void* my_free(void* block) {

}
