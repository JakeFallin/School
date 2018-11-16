#include "../../include/my.h"

int my_strrindex(char* str, char ch){
	int i = 0;
	int last = -1;
	if(str == NULL){return -1;}
	while(str[i] != '\0'){
		if(str[i] == ch){
			//my_char((char)(48+i));
			last = i;
		}
		i = i + 1;
	}
	return last;
}
