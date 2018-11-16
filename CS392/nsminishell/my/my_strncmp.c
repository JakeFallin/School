/*
Pre: Receives two char*s and an int n
Post: Compares the first n characters of both char*s and returns a number depending on which is first
*/

#include "../lib/my.h"

int my_strncmp(char *x, char *y, int n)
{
    int i;

    i = 0;

    if(x != NULL && y != NULL && n > 0)
    {
        for(;(*x != '\0' || *y != '\0') && i < n; x++, y++, i++)
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