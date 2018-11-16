/*
Pre: Receives a pointer to the head of the list and an integer n
Post: Returns the element found in the node at position n in the list
*/

#include "../lib/mylist.h"

void *elem_at(t_node *h, int i)
{
    if(h != NULL && i >= 0)
    {
        for(; h->next != NULL && i > 0; i--, h = h->next)
            ;
        return h->elem;
    }
}