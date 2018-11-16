#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
char* my_strfind(char *s, char c)
{	
	if(s == NULL)
		return -1;

	int len=my_strlen(s);

	for(int i=0; i<len; i++)
	{
		if(s[i]==c)
			return &s[i];
	}

	return -1;
}

char* my_strrfind(char *s, char c)
{
	if(s == NULL)
		return -1;

	int len=my_strlen(s);

	int i=0;
	char *val=NULL;

	while (s[i]!='\0')
	{
		if (s[i]==c)
			val=&c;

		i++;
	}

	return val;
}

int my_strcmp(char *a, char *b)
{
	if(a==NULL && b==NULL)
		return 0;
	if(a==NULL)
		return -1;
	if(b==NULL)
		return 1;

	int la=my_strlen(a);
	int lb=my_strlen(b);

	for(int i=0; i<la && i<lb; i++) {
		if(a[i]<b[i])
			return -1;
		if(a[i]>b[i])
			return 1;
	}

	if(la<lb)
		return -1;
	if(la>lb)
		return 1;

	return 0;
}

int my_strncmp(char *a, char *b, int n)
{
	if(a==NULL && b==NULL)
		return 0;
	if(a==NULL)
		return -1;
	if(b==NULL)
		return 1;

	int la=my_strlen(a);
	int lb=my_strlen(b);

	for(int i=0; ((i<la && i<lb) && (i<n)); i++) {
		if(a[i]<b[i])
			return -1;
		if(a[i]>b[i])
			return 1;
	}

	if(la<lb)
		return -1;
	if(la>lb)
		return 1;

	return 0;
}

char* my_strcpy(char *dst, char *src) {
	char *temp = dst;
	while(*dst++ = *src++);
	return temp;
}

char* my_strncpy(char *dst, char *src, int n) {
	char *temp = dst;
	while((*dst++ = *src++) && (n-- > 1));
	return temp;
}


char* my_strcat(char *dst, char *src) {

	if(dst != NULL && src == NULL) 
		return -1;

	int dstl = my_strlen(dst);
	int srcl = my_strlen(src);
	int i = 0;
	for(i = 0; ((i < srcl) && (src[i] != '\0')); i++) {
		dst[dstl + i] = src[i];
	}
	dst[dstl + i] = '\0';
	return dst;
}


char* my_strdup(char *str) {

	if(str == NULL)
		return -1;
	char* result = malloc(my_strlen(str) + 1);
	result = my_strcpy(result, str);
	result[my_strlen(str)] = '\0';
	return result;
}

char* my_strconcat(char *a, char *b) {

	int al = my_strlen(a);
	int bl = my_strlen(b);

	char *result = (char*) malloc(al+bl);
	result = my_strcpy(result, my_strcat(a, b));
	return result;
}

char* my_strnconcat(char *a, char *b, int n) {

	int al = my_strlen(a);
	int bl = my_strlen(b);

	if(!(n > 0))
		return a;
	else {
		char *tmp = (char*) malloc(n);
		b = my_strncpy(tmp, b, n);
	}
	char *result = (char*) malloc(al+bl);
	result = my_strcpy(result, my_strcat(a, b));
	return result;

}

//helper method for my_atoi
bool atoi_helper(char x) {
	if(x >= '0' && x <= '9')
		return true;
	return false;
}

int my_atoi(char *n) {
	
	if(n == NULL) 
		return -1;
	
	int result = 0;
	int sign = 1;

	for(int i = 0; n[i] != '\0'; ++i) {
		if(n[i] == '-') {
			sign *= -1;
		}
		if(atoi_helper(n[i])) {
			if(i > 0 && (atoi_helper(n[i-1])))
				result = n[i] - '0' + (result*10);
		}
		else {

		}
	}
	return (result * sign);

}




