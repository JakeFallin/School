/*
Pre: Receives two strings
Post: Returns the concatenation of the two strings in a newly allocated string pointer
*/

#include "../lib/my.h"

char *my_strconcat(char *x, char *y)
{
    char *r;

        r = (char*)xmalloc(my_strlen(x) + my_strlen(y));
        my_strcat(my_strdup(x), my_strdup(y));
        r = my_strcpy(r, my_strcat(my_strdup(x), my_strdup(y)));

    return r;
}