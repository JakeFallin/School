#include "../../include/list.h"

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	//allocate memory
	struct s_node* point = malloc(sizeof(struct s_node));
	
	//get actual node
	point->elem = elem;
	point->next = next;
	point->prev = previous;
	
	return point;
}
