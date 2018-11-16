/*
Pre: Receives a string
Post: Converts the string to a vector and returns a pointer to the vector
*/

#include "../lib/my.h"

char **my_str2vect(char *s)
{
    char *b;
    char *e;
    char f;
    int len;
    char **r;

    if(s != NULL)
    {
        b = s;
        e = s;
        f = 0;
        len = 0;
        /*
        my_str("Beginning First For... \n");
        */
        for(;*s != '\0'; s++)
        {
            if(f == 1 && *s != ' ')
            {
                f = 0;
                len++;
            }

            if(*s == ' ')
                f = 1;
        }
        len++;
        /*
        my_str("First For Completed \n Length: ");
        my_int(len);
        my_str("\n");
        */
        s = b;
        r = (char**)xmalloc((len + 1) * sizeof(char*));
        r[len] = NULL;
        len = 0;

        for(;*s != '\0'; s++)
        {
            if(f == 1 && *s != ' ')
            {
                e++;
                *e = '\0';
                /*
                my_str("Putting into vector: ");
                my_str(b);
                my_str("\n");
                */
                r[len] = my_strdup(b);
                *e = ' ';
                len++;
                f = 0;
                b = s;
            }
            if(*s != ' ')
                e =s;
            else
                f = 1;
        }
        e++;
        *e = '\0';
        /*
        my_str("Putting into vector: ");
        my_str(b);
        my_str("\n");
        */
        r[len] = my_strdup(b);


        return r;
    }
}
