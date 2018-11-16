/*
Pre: Receives the pointer to the head of the list of ints
Post: Prints a traversal of the list in order
*/

#include "../lib/mylist.h"

void traverse_int(t_node *h)
{
    if(h != NULL)
    {
        my_int(*((int*)(h->elem)));
        my_char(' ');
        traverse_int(h->next);
    }
}