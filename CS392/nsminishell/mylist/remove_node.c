/*
Pre: Receives the pointer to the head of the list
Post: Removes the head of the list and returns it, making the new head the next element in the list
*/

#include "../lib/mylist.h"

void *remove_node(t_node **h)
{
    if(h != NULL && *h != NULL)
    {
        void *t = (t_node*)(*h)->elem;
        t_node *f = *h;

        *h = f->next;
        free(f);
        f = NULL;
        return t;
    }
}