/*
Pre: Accepts a char*
Post: Returns a pointer to the char* allocated in memory
*/

#include "../lib/my.h"

char *my_strdup(char *c)
{
    if(my_strlen(c) != -1)
    {
        char *r = (char*)xmalloc(my_strlen(c) * (int)sizeof(char));

        my_strcpy(r, c);
        return r;
    }
    else
        return NULL;

}