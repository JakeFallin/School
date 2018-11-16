/*
Pre: Receives a number of bytes
Post: Allocates that number of bytes using malloc and returns a pointer that points to the memory location
*/

#include "../lib/my.h"

void *xmalloc(int n)
{
    void *p;
    p = malloc(n);
    if(p == 0)
    {
        my_str("Virtual Memory Exhausted \n");
        exit(1);
    }

    return p;
}