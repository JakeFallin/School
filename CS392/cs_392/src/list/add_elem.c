#include "../../include/list.h"

void add_elem(void* elem, struct s_node** head){
	//Make sure things are not null
	if(elem == NULL){
		my_str("Attempted to add node with NULL elem\n");
		return;
	}
	if(head == NULL){
		my_str("Attempted to add with a null head\n");
		return;
	}
	if(*head == NULL){
		my_str("Attempted to add with a null head node\n");
		return;
	}

	//create new node with elem
	struct s_node* newnode = new_node(elem, NULL, NULL);

	//add the node to the start of the list
	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;
}

