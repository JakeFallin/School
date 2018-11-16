#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	int x=1, y=2;

	x=fork();
	y=fork();

	printf("x:%d, y:%d", x, y);

	if(x!=0)printf("Type1\n");
	if(y!=0)printf("Type2\n");

	if(x>0 || y>0)printf("Type3\n");
	if(x==0 && y==0)printf("Type4\n");
	if(x!=0 && y!=0)printf("Type5\n");
}