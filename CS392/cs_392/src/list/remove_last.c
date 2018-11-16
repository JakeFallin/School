#include "../../include/list.h"

void* remove_last(struct s_node** head){
	void* rv;
	struct s_node* cn = *head;
	//make sure things arent null
	if(head == NULL){
		my_str("Can't remove, this pointer is NULL\n");
		return NULL;
	}
	if(*head == NULL){
		my_str("Can't remove, pointer references NULL pointer.\n");
		return NULL;
	}
	//if its just one node, free it
	if(cn->next == NULL){
		rv = cn->elem;
		free(cn);
		return rv;
	}
	//get to the end of list and remove node
	while(cn->next != NULL){
		cn = cn->next;
	}
	rv = cn->elem;
	cn->prev->next = NULL;
	free(cn);
	return rv;
}
