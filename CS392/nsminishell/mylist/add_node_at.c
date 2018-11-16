/*
Pre: Receives a preallocated node, a pointer to the head of the list, and an integer n
Post: Inserts the given node into the list at the position n in the list
*/

#include "../lib/mylist.h"

void add_node_at(t_node *n, t_node **h, int i)
{
    if(n != NULL && (*h) != NULL && h != NULL)
    {
        t_node *t = *h;

        if(i <= 0)
            add_node(n, h);
        else
        {
            for(; (i-1) > 0 && t->next != NULL; t = t->next, i--)
                ;
            n->next = t->next;
            t->next = n;
        }
    }
}