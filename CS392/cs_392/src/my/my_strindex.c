#include "../../include/my.h"

int my_strindex(char* str, char ch){
	int i = 0;
	if(str == NULL){return -1;}
	while(str[i] != '\0'){
		if(str[i] == ch){
			//my_char((char)(48+i));
			return i;
		}
		i = i + 1;
	}
	return -1;
}
