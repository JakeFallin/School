/*
Pre: Accepts a number to represent as well as a char* that contains a number of symbols to be used as the base
Post: Prints the given number to the screen in the specified base
*/

#include "../lib/my.h"

void my_num_base(int i, char * c)
{
    if(i < 0)
    {
        i = i * -1;
        my_char('-');
    }
    if(my_strlen(c) > 0)
    {
        int b = my_strlen(c);
        unsigned int a = 1;

        while((a*b) < i)
        {
            a = a* b;
        }

        while(a > 0)
        {
            my_char(c[i/a]);
            i = i % a;
            a = a / b;
        }
    }
}