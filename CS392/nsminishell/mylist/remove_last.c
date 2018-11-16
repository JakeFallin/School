/*
Pre: Receives a pointer to the head of the list
Post: Removes the last node in the list and returns it, then frees the pointer to the removed node
*/

#include "../lib/mylist.h"

void *remove_last(t_node **h)
{
    if(h != NULL && *h != NULL)
    {
        t_node *t = *h;
        void *r;

        for(; t->next->next != NULL; t = t->next)
            ;

        r= (t_node*)(t->next)->elem;
        free(t->next);
        t->next = NULL;

        return r;
    }
}