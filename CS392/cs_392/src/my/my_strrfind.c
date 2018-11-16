#include "../../include/my.h"

char* my_strrfind(char* str, char chara){
	int l = my_strlen(str);
	char* result = NULL;
	for(int i = 0; i < l; i++){
		if(str[i] == chara){
			result = &str[i];
		}
	}
	
	return result;
}
