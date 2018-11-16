/*
Pre: Receives two strings and an integer n
Post: Returns the concatenation of the first string and the first n characters of the second string in a pointer to newly allocated string
*/

#include "../lib/my.h"

char *my_strnconcat(char *x, char *y, int n)
{
    char *r;
    if(n > 0)
        y = my_strncpy((char*)xmalloc(n), y, n);
    else
        return x;
    r = (char*)xmalloc(my_strlen(x) + my_strlen(y));
    my_strcat(my_strdup(x), my_strdup(y));
    r = my_strcpy(r, my_strcat(my_strdup(x), my_strdup(y)));

    return r;
}