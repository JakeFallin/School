#include "../../include/my.h"

char* my_strncpy(char* dst, char* src, int n){
	int dstlen = my_strlen(dst);
	int srclen = my_strlen(src);
	if(srclen > n){srclen = n;}
	int limit;
	int i;
	if(dst == NULL){
		dst = "";
		return dst;
	}
	if(n == 0){
		dst[0] = '\0';
		return dst;
	}
	if(src == NULL){
		dst[0] = '\0';
		return dst;
	}
	if(dstlen < srclen){
		limit = dstlen;
	}else{
		limit = srclen;
	}
	for(i = 0; i < limit; i++){
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}
