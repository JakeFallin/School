/*
Pre: Receives a char* and a char
Post: Finds the char inside the char* and returns a pointer pointing to the position of the last matching char found
*/

#include "../lib/my.h"

char *my_rfind(char *s, char c)
{
    char *f;
    f = NULL;

    if(s != NULL)
    {
        while(*s != '\0')
        {
            if(*s == c)
            {
                f = s;
            }
            s++;
        }
    }
    return f;
}