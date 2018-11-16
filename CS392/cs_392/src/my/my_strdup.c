#include "../../include/my.h"

char* my_strdup(char* str){
	int strlen = my_strlen(str);
	char* newstr = malloc(strlen+1);
	int x;
	if(strlen == -1){return NULL;}
	for(x = 0; x < strlen; x++){
		newstr[x] = str[x];
	}
	newstr[x] = '\0';
	return newstr;	
}
