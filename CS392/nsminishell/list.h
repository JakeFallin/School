/*
An implementation of the Linked List data structure
*/
#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "my.h"

typedef struct s_node
{
    struct s_node *next;
    void *elem;
} t_node;

t_node *new_node(void*, t_node*);
void add_node(t_node*, t_node**);
void add_elem(void*, t_node**);
void append(t_node*, t_node**);
void add_node_at(t_node*, t_node**, int);

void *remove_node(t_node**);
void *remove_node_at(t_node**, int);
void *remove_last(t_node**);

int count_nodes(t_node*);

void empty_list(t_node**);

t_node *node_at(t_node*, int);
void *elem_at(t_node*, int);

void traverse_char(t_node*);
void traverse_string(t_node*);
void traverse_int(t_node*);

#endif