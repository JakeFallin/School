/*
Pre: Receives a vector
Post: Returns a string containing all of the separate strings from the vector separated by white spaces
*/

#include "../lib/my.h"

char *my_vect2str(char** vect)
{
    char *r;
    char **t = vect;
    int len = 0;

    if(vect != NULL)
    {
        for(; *vect != NULL; vect++)
        {
            if(vect + sizeof(char*) != NULL && len > 1)
                len++;

            len += my_strlen(*vect);
        }

        r = xmalloc(len * sizeof(char));
        vect = t;

        for(; *vect != NULL; vect++)
        {
            r = my_strcat(r, *vect);
            r = my_strcat(r, " ");
        }

        r[len] = '\0';
    }

    return r;
}