/*
Pre: Receives a pointer to the pointer to the head of the list
Post: Empties all nodes from the list and frees them
*/

#include "../lib/mylist.h"

void empty_list(t_node **h)
{
    if(h != NULL && *h != NULL)
    {
        t_node **t = h;

        for(;*t != NULL; remove_node(t))
            ;
    }
}