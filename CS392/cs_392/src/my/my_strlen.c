#include "../../include/my.h"

int my_strlen(char* str){
	int i = 0;
	int len = 0;
	char* qf = "";
	if(str == NULL){return -1;}
	if(str == qf){return 0;}
	if(str[0] == '\0'){return 0;}
	while(str[i] != '\0'){
		len++;
		i++;
	}
	return len;
}
