#include "../../include/list.h"

void* remove_node(struct s_node** node){
	void* rv;
	struct s_node* temp;
	//make sure things arent null
	if(node == NULL){
		my_str("Can't remove, this pointer is NULL\n");
		return NULL;
	}
	if(*node == NULL){
		my_str("Can't remove, pointer references NULL pointer.\n");
		return NULL;
	}
	//if node is not part of a list, just free it
	if((*node)->next == NULL && (*node)->prev == NULL){
		rv = (*node)->elem;
		free(*node);
		return rv;
	};
	//remove the node carefully
	if((*node)->prev == NULL){
		(*node)->next->prev = NULL;
		rv = (*node)->elem;
		temp = *node;
		*node =(*node)->next;
		free(temp);
		return rv;
	}else if((*node)->next == NULL){
		rv = (*node)->elem;
		(*node)->prev->next = NULL;
		free(*node);
		return rv;
	}else{
		(*node)->prev->next = (*node)->next;
		(*node)->next->prev = (*node)->prev;
		rv = (*node)->elem;
		free(*node);
		return rv;
	}
}
