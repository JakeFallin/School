#include "../../include/my.h"

int my_atoi(char* str){
	int i;
	int started = 0;
	int result = 0;
	int neg = 0;
	int strlen = my_strlen(str);
	for(i = 0; i < strlen; i++){
		if(str[i] == '-' && started == 0){
			if(neg == 0){
				neg = 1;
			}else{
				neg = 0;
			}
		}
		if((str[i] < '0' || str[i] > '9') && started == 1){
			if(neg == 1){
				result *= -1;
			}
			return result/10;
		}
		if(str[i] >= '0' && str[i] <= '9'){
			started = 1;
			result += (str[i] - '0');
			result *= 10;
		}
	}
	if(neg == 1){
		result *= -1;
	}
	return result/10;
}
