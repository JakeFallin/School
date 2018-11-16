#include "../../include/my.h"

char* my_strcat(char* dst, char* src){
    int x;
	if(dst == NULL || src == NULL){
		return dst;
	}
	int dstlen = my_strlen(dst), srclen = my_strlen(src);
	for(x = 0; x < srclen; x++){
		dst[dstlen + x] = src[x];
	}
    dst[dstlen + x] = '\0';
	return dst;
}
