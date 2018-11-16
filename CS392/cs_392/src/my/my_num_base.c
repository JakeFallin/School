#include "../../include/my.h"

void my_num_base(int x, char* str){
	int base = my_strlen(str);
	int place = 0;
	int curr;
	long xx = (long)x;
	//some edge cases
	if(str == NULL || str[0] == '\0'){
		my_str("Error. NULL or Empty Set.");
		return;
	}
	if(xx < 0){
		my_char('-');
		xx *= -1;
	}
	//if given only one char to use
	if(base == 1){
		if(xx == 0){return;}
		while(place < xx){
			my_char(str[0]);
			place++;
		}
		return;
	}
	if(xx == 0){
		my_char(str[xx]);
	}
	long temp = xx;
	while(temp > 0){
		temp = temp / base;
		place++;
	}
	while(place > 0){
		temp = xx;
		for(int inc = 0; inc < place; inc++){
			curr = temp % base;
			temp = temp / base;
		}
		place--;
		my_char(str[curr]);
	}
}
