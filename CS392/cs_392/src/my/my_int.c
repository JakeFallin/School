#include "../../include/my.h"

void my_int(int i){
	int place = 0;
	long temp = (long)i;
	int curr;
	long ii = (long)i;
	if(ii == 0){
		my_char('0');
		return;
	}
	if(ii < 0){
		my_char('-');
		ii *= -1;
		temp *= -1;
	}
	while(temp > 0){
		temp = temp / 10;
		place++;
	}
	while(place > 0){
		temp = ii;
		for(int x = 0; x < place; x++){
			curr = temp %10;
			temp = temp / 10;
		}
		place--;
		my_char(curr + '0');
	}
}
