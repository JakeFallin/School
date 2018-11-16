/*
Pre: Receives a pointer to the head of the list
Post: Returns the amount of nodes contained in the list
*/

#include "../lib/mylist.h"

int count_nodes(t_node *h)
{
    if(h != NULL)
    {
        int i = 1;
        for(; h->next != NULL; ++i, h = h->next)
                ;
        return i;
    }
}