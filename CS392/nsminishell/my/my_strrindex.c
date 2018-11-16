/*
Pre: Receives a char* and a char to find in the char*
Post: Returns the last index that the char appears in
*/

#include "../lib/my.h"

int my_strrindex(char *s, char c)
{
    int i = 0;
    int r = -1;
    if(s != NULL)
    {
        while(s[i] != '\0')
        {
            if(s[i] == c)
            {
                r = i;
            }
            i++;
        }
    }

    return r;
}