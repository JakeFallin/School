/*
Pre: Receives two char*s
Post: Concats the second char* onto the first char* and returns the pointer to the full char*
*/

#include "../lib/my.h"

char *my_strcat(char *x, char *y)
{
    char *t;

    if(x != NULL && y != NULL)
    {
        t = x;
        for(;*x != '\0'; x++)
            ;
        for(;*y != '\0'; x++, y++)
            *x = *y;
        x++;
        *x = '\0';
    }
    return t;
}