#include "../../include/list.h"

void empty_list(struct s_node** head){
	struct s_node* cn;
	struct s_node* pn;	
	//check nulls
	if(head == NULL || *head == NULL){
		my_str("List already empty.");
		return;
	}
	cn = *head;
	while(cn->next != NULL){
		pn = cn;
		cn = cn->next;
		free(pn);
	}
	free(cn);
	*head = NULL;
}
