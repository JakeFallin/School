#include "../../include/my.h"

int my_strcmp(char *a, char *b){
	int x, len, lena = my_strlen(a), lenb = my_strlen(b);
	
	//NULL checks
    if( a == NULL && b == NULL)
        return 0;
    if(a == NULL)
        return -1;
    if(b == NULL)
        return 1;

    if(lena > lenb){
        len = lena;
    }else{
        len = lenb;
    }

    //go until you find a difference
	for(x = 0; x <= len; x++){
		if(a[x] < b[x])
			return -1;
		if(a[x] > b[x])
			return 1;
    }
    if(x == lena)
        return -1;
    if(x == lenb)
        return 1;
        
    return 0;
}
