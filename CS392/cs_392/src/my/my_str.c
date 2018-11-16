#include "../../include/my.h"

void my_str(char* str){
	int x = 0;
	if(str == NULL){return;}
	while(str[x] != '\0'){
		my_char(str[x]);
		x = x + 1;
	}
}
