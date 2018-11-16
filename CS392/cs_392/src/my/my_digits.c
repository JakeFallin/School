#include "../../include/my.h"

void my_digits(){
	for(int x = 0; x < 10; x = x + 1){
		my_char((char)(48+x));
	}
}
