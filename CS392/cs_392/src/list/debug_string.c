#include "../../include/list.h"

void debug_string(struct s_node* head){
	struct s_node* currnode;
	
	//check for null things
	if(head == NULL){
		my_str("This pointer is NULL\n");
		return;
	}
	if(head->elem == NULL){
		my_str("The elem of this head is NULL\n");
		return;
	}
	currnode = head;
	
	while(currnode != NULL){
		my_str("( ");
		if(currnode->prev == NULL){
			my_str("NULL");
		}else{
			my_str(currnode->prev->elem);
		}
		my_str(" <- ");
		my_str(currnode->elem);
		my_str(" -> ");
		if(currnode->next == NULL){
			my_str("NULL");
		}else{
			my_str(currnode->next->elem);
		}
		my_str(")\0");
		currnode = currnode->next;
	}
	my_char('\n');
}