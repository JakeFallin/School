/*
Pre: Receives the pointer to the head of a list of chars
Post: Prints a complete traversal of the list in order
*/

#include "../lib/mylist.h"

void traverse_char(t_node *h)
{
    if(h != NULL)
    {
        my_char(*((char*)(h->elem)));
        my_char(' ');
        traverse_char(h->next);
    }
}