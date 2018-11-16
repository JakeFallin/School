#include "../../include/my.h"

int my_revstr(char *str){
	int len = my_strlen(str);
	char temp;
	int beg = 0;
	int end = len - 1;
	while(beg < end){
		temp = str[beg];
		str[beg] = str[end];
		str[end] = temp;
		beg++;
		end--;
	}
	return len;
}
