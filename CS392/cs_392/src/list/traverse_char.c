#include "../../include/list.h"

void traverse_char(struct s_node* head){
	//check for nulls
	if(head == NULL){
		my_str("This head is null");
		return;
	}
	//otherwise go ahead and parse carefully
	while(head->next != NULL){
		print_char(head);
		head = head->next;
	}
	print_char(head);
}
