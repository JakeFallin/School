#include "my.h"

char* my_vect2str(char **x){
	char* r = malloc(100);
	int i = 1;
	if(x == NULL){
		my_str("NULL pointer.");
	}
	while(x[i] != NULL){
		my_strcat(r, x[i]);
		my_strcat(r, " ");
		i++;
	}
	return r;
}
