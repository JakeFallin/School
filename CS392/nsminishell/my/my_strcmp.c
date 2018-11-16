/*
Pre: Accepts two char*s and compares them
Post: Compares the char*s alphabetically and returns a number based on which is first
*/

#include "../lib/my.h"

int my_strcmp(char *x, char *y)
{
    if(x != NULL && y != NULL)
    {
        for(;*x != '\0' || *y != '\0'; x++, y++)
        {
            if(*x < *y)
                return -1;
            if(*y < *x)
                return 1;
        }
        return 0;
    }
    else
    {
        if(x == NULL && y == NULL)
            return 0;
        else if(x == NULL)
            return -1;
        else if(y == NULL)
            return 1;
    }
}