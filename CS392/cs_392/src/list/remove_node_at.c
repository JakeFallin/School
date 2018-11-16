#include "../../include/list.h"

void* remove_node_at(struct s_node** head, int n){
	void* rv;
	struct s_node* cn;
	int i = 0;
	if(n < 0){n = 0;}
	//make sure things arent null
	if(head == NULL){
		my_str("Can't remove, this pointer is NULL\n");
		return NULL;
	}
	if(*head == NULL){
		my_str("Can't remove, pointer references NULL pointer.\n");
		return NULL;
	}
	//if node is not part of a list, just free it
	if((*head)->next == NULL && (*head)->prev == NULL){
		rv = (*head)->elem;
		free(*head);
		return rv;
	};
	//navigate to node n or last node
	cn = *head;
	while(cn->next != NULL && i < n){
		cn = cn->next;
		i++;
	}
	//remove the node carefully
	if(cn->prev == NULL){
		cn->next->prev = NULL;
		rv = cn->elem;
		*head = cn->next;
		free(cn);
		return rv;
	}else if(cn->next == NULL){
		rv = cn->elem;
		cn->prev->next = NULL;
		free(cn);
		return rv;
	}else{
		cn->prev->next = cn->next;
		cn->next->prev = cn->prev;
		rv = cn->elem;
		free(cn);
		return rv;
	}
}
