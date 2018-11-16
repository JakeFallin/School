/*
Pre: Receives a string
Post: Returns the length of said string
*/

#include "../lib/my.h"

int my_strlen(char *c)
{
    int i = 0;
    if(c == NULL)
        return i;

    while(c[i] != '\0')
    {
        i++;
    }

    return i;
}