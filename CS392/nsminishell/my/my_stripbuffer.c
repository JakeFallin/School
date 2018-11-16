/*
Pre: Receives buffered input fromt the keyboard
Post: Returns the sanitized buffer
*/

#include "../lib/my.h"

char *my_stripbuffer(char *s)
{
    int i;

    i = 0;

    for(;s[i] != '\n' && s[i] != '\0'; i++)
        ;
    s[i] = '\0';

    return s;
}