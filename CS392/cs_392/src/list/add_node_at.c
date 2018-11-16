#include "../../include/list.h"

void add_node_at(struct s_node* node, struct s_node** head, int n){
	int loc = 0;
	struct s_node* cn;
	//Make sure things are not null
	if(node == NULL){
		my_str("node is null\n");
		return;
	}
	if(node->elem == NULL){
		my_str("node elem is null\n");
		return;
	}
	if(head == NULL){
		my_str("head is null\n");
		head = &node;
		*head = node;
		return;
	}
	if(*head == NULL){
		my_str("head is null\n");
		*head = node;
		node->prev = NULL;
		node->next = NULL;
		return;
	}
	cn = *head;

	//cases
	if(n < 0){n = 0;}
	if(n == 0){
		//if n is 0 add the node to the start of the list
		node->next = *head;
		node->prev = NULL;
		(*head)->prev = node;
		*head = node;
	}else{
		while(loc < n){
			//if n is bigger than length of list, append
			if(cn->next == NULL){
				cn->next = node;
				node->prev = cn;
				node->next = NULL;
				return;
			}
			cn = cn->next;
			loc++;
		}
		node->next = cn;
		node->prev = cn->prev;
		cn->prev = node;
		node->prev->next = node;
	}
}
