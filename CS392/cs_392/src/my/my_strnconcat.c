#include "../../include/my.h"

char* my_strnconcat(char* a, char* b, int n){
	//Same as my_strconcat except:
	// Copies all of a and then n chars or length of b
    int alen = my_strlen(a);
    int blen = my_strlen(b);
    int ind;
    char* new;
    if(a == NULL && b == NULL){
        new = malloc(0);
        new = "";
        return new;
    }
    if(n < blen)
        blen = n;
    new = malloc(alen+blen+1);
    for(ind = 0; ind < alen; ind++){
        new[ind] = a[ind];
    }
    for(ind = 0; ind < blen; ind++){
        if(alen == -1){
            new[ind] = b[ind];
        }else{
            new[ind + alen] = b[ind];
        }
    }
    if(a == NULL){
        new[blen+1] = '\0';
    }else if(b == NULL){
        new[alen+1] = '\0';
    }else{
        new[alen + blen + 1] = '\0';
    }
    return new;

/*
	int alen = my_strlen(a);
	int blen = my_strlen(b);
	if(blen > n){blen = n;}
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
	return new;*/
}

