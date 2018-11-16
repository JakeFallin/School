#include "../../include/list.h"

void add_node(struct s_node* node, struct s_node** head){
	if(head == NULL){
		head = &node;
		*head = node;
		return;
	}else{
		add_node_at(node, head, 0);
	}
}
