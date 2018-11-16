/*
Pre: accepts an element of any type as a pointer and  a pointer to the next element in the list
Post: Returns the pointer to a newly allocated node that contains the given element and given pointer to next element
*/

#include "../lib/mylist.h"

t_node *new_node(void *e, t_node *n)
{
    if(e != NULL)
    {
        t_node *node = (t_node*)xmalloc(sizeof(t_node));
        node->next = n;
        node->elem = e;

        return node;
    }
}