/*
Pre: Receives a vector
Post: Prints the contents of the vector to the screen
*/

#include "../lib/my.h"

void my_printvect(char **v)
{
    for(;*v != NULL; v++)
    {
        my_str(*v);
        my_str(" ");
    }

}