/*
Pre: Receives two strings
Post: Overwrites string 1 with string 2, then returns the pointer to string 1
*/

#include "../lib/my.h"

char *my_strcpy(char *x, char *y)
{
    int i;

    if(x != NULL && y != NULL)
        for(i = 0; *y != '\0'; i++, y++)
            x[i] = *y;

    return x;
}