/*
Pre: Receives the pointer to the head of the list and an integer n
Post: Removes a node in the list at position n and returns it
*/

#include "../lib/mylist.h"

void *remove_node_at(t_node **h, int i)
{
    if(h != NULL && *h != NULL && i >= 0)
    {
        t_node *t = *h;
        void *r;
        t_node *f;

        for(; (i-1) > 0 && t->next->next != NULL; t = t->next, i--)
            ;
        f = t->next;
        r= (t_node*)(t->next)->elem;
        t->next = t->next->next;
        free(f);
        f = NULL;
        return r;
    }
}