#include "../../include/my.h"

char* my_strfind(char* str, char chara){
	int l = my_strlen(str);
	for(int i = 0; i < l; i++){
		if(str[i] == chara){
			return &str[i];
		}
	}
	return NULL;
}
