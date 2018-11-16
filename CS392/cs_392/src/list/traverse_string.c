#include "../../include/list.h"

void traverse_string(struct s_node* head){
	//check for nulls
	if(head == NULL){
		my_str("This head is null");
		return;
	}
	//otherwise go ahead and parse carefully
	while(head->next != NULL){
		print_string(head);
		head = head->next;
	}
	print_string(head);
}
