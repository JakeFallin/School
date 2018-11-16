/* Pre: Nothing
Post: Prints entire alphabet
*/

#include "../lib/my.h"

void my_alpha()
{
    char c = 'A';
    while(c <= 'Z')
    {
        my_char(c);
        c++;
    }
}