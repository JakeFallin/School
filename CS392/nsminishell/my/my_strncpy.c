/*
Pre: Receives two strings and an integer n
Post: Overwrites n characters from string two onto the beginning of string one, returns the pointer to string one
*/

#include "../lib/my.h"

char *my_strncpy(char *x, char *y, int n)
{
    int i;

        if(x != NULL && y != NULL && n > 0)
            for(i = 0; i < n; i++)
                x[i] = y[i];

    return x;
}