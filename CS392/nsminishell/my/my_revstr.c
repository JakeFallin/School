/*
Pre: Receives a char*
Post: Returns the length of the string and reverses the given string
*/

#include "../lib/my.h"

int my_revstr(char *c)
{
    int i = 0;
    int l = my_strlen(c) - 1;
    char t;

    if(c == NULL)
        return 0;

    while(i < (l/2 + 1))
    {
        t = c[i];
        c[i] = c[l - i];
        c[l - i] = t;
        i++;
    }
    return l;
}