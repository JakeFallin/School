/*
Pre: recives a preallocated node and the pointer to the head
Post: Adds the given node to the end of the list
*/

#include "../lib/mylist.h"

void append(t_node *n, t_node **h)
{
    if(n != NULL && h != NULL && *h != NULL)
    {
        t_node *t = *h;
        for(; t->next != NULL; t = t->next)
            ;
        t->next = n;
    }
}