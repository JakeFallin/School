#include "../../include/list.h"

void append(struct s_node* node, struct s_node** head){
	struct s_node* cn;
    if((head != NULL) && (node != NULL) && (node->elem != NULL)){
        if(*head != NULL){
            cn = *head;
            while(cn->next != NULL)
                cn = cn->next;
            cn->next = node;
            node->prev = cn;
        }
    }
}
