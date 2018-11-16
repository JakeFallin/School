/*
Pre: Receives a char* and a char
Post: Finds the char inside the char* and returns a pointer pointing to the position of the first matching char found
*/

#include "../lib/my.h"

char *my_find(char *s, char c)
{
    if(s != NULL)
    {
        while(*s != '\0')
        {
            if(*s == c)
                return s;
            s++;
        }
    }
    return NULL;
}