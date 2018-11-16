/*
Pre: Receives a pointer to the head of the list and an integer n
Post: Returns a pointer to the node in the list at the position n
*/

#include "../lib/mylist.h"

t_node *node_at(t_node *h, int i)
{
    if(h != NULL && i >= 0)
    {
        for(; h->next != NULL && i > 0; i--, h = h->next)
            ;
        return h;
    }
}