#include "../../include/list.h"

int count_s_nodes(struct s_node* head){
	int ct = 0;
	//check nulls
	if(head == NULL){
		my_str("No list -- head node is null.\n");
		return 0;
	}
	if(head->next == NULL){
		return 1;
	}
	while(head->next != NULL){
		head = head->next;
		ct++;
	}
	ct++;
	return ct;
}
