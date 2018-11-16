/*
Pre: Receives the pointer to the head of a list of strings
Post: Prints a traversal of the entire list in order
*/

#include "../lib/mylist.h"

void traverse_string(t_node *h)
{
    if(h != NULL)
    {
        my_str((char*)h->elem);
        my_char(' ');
        traverse_string(h->next);
    }
}