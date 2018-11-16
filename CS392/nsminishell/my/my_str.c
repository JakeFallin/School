/* Pre: Accepts a char*
Post: Prints it to screen */

#include "../lib/my.h"

void my_str(char *c)
{
    int i = 0;
    
    if(c != NULL)
    {
        while(c[i] != '\0')
        {
            my_char(c[i]);
            i++;
        }
    }

}