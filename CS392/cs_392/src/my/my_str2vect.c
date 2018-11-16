#include "my.h"

char** my_str2vect(char* str){
	int sz = my_strlen(str);
	char** vect = (char **)malloc(((sz/2)+1) * sizeof(char*));
	int cnt = 0;
	int ind = 0;
	int len = 0;
	char* awe = "";	
	
	if(str == NULL){
		vect[0] = NULL;
		return vect;
	}
	
	while(str[ind] != '\0'){
		if(str[ind] == '\t' || str[ind] == ' ' || str[ind] == '\n'){
			if(len == 0){
				str = str + 1;
				continue;
			}
			vect[cnt] = my_strnconcat(awe, str, len);
			ind++;
			cnt++;
			str = str+len+1;
			len = 0;
			ind = 0;
		}else{
			ind++;
			len++;
		}
	}
	vect[cnt] = my_strnconcat(awe, str, len);
	str = str+len;
	vect[cnt+1] = NULL;
	return vect;
}
