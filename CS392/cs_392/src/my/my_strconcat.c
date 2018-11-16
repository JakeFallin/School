#include "../../include/my.h"

char* my_strconcat(char* a, char *b){
	//Allocates new memory 
 	//Copies concatenated strings in that new memory 
	// Returns pointer to it
	// If both NULL return NULL
	int alen = my_strlen(a);
	int blen = my_strlen(b);
	if(alen + blen == -2){
		return NULL;
	}
	char* new = malloc(alen+blen+1);
	int index;
	for(index = 0; index < alen; index++){
		new[index] = a[index];
	}
	for(index = 0; index < blen; index++){
		if(a == NULL || a[0] == '\0'){
			new[index] = b[index];
		}
		else{
			new[index+alen] = b[index];
		}
	}
	if(a == NULL || a[0] == '\0'){new[blen+1] = '\0';}
	else if(b == NULL || b[0] == '\0'){new[alen+1] = '\0';}	
	else {new[alen+blen] = '\0';}
	return new;
}
