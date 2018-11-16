/*
Pre: Accepts a preallocated node as well as the pointer to the head of the list
Post: Adds the given node to the front of the list and replaces the head with the newly given node
*/

#include "../lib/mylist.h"

void add_node(t_node *n, t_node **h)
{
    if(n != NULL && h != NULL)
    {
        if(*h == NULL && n != NULL)
            *h = n;
        else {
            n->next=*h;
            *h = n;
        }
    }
}