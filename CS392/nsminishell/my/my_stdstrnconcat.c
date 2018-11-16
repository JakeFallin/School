/*
Pre: Receives 2 strings and an integer n
Post: Concatenates the first n chars of string two onto string one and returns the result in a newly allocated string. Returns NULL if n is greater than the length of string two
*/

#include "../lib/my.h"

char * my_stdstrnconcat(char *x, char *y, int n)
{
    if(!(n > my_strlen(y)))
        return my_strnconcat(x, y, n);
    else
        return NULL;
}