#include "../../include/list.h"

struct s_node* node_at(struct s_node* head, int n){
	int i = 0;
	//check for nulls
	if(head == NULL){
		my_str("This head is NULL\n");
		return NULL;
	}
	if(n < 0){n = 0;}
	while(i < n){
		if(head->next != NULL){
			head = head->next;
		}else{
			return head;
		}
		i++;
	}
	return head;
}
