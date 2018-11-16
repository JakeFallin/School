/*
Pre: Receives an element in the form of a pointer and a pointer to the head of the list
Post: adds the given element at the end of the list in a newly created node
*/

#include "../lib/mylist.h"

void add_elem(void *e, t_node **h)
{
    if(e != NULL && *h != NULL && h != NULL)
    {
        *h = new_node(e, *h);
    }
}