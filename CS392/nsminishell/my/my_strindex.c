/*
Pre: Receives a char* and a char.
Post: Looks for the char inside the char* and returns the index in which the char appears
*/

#include "../lib/my.h"

int my_strindex(char *s, char c)
{
    int i = 0;
    if(s != NULL)
    {
        while(s[i] != '\0')
        {
            if(s[i] == c)
            {
                return i;
            }
            i++;
        }
    }


    return -1;
}