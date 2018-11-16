#include "../../include/list.h"

void print_char(struct s_node* node){
	if(node == NULL){
		my_str("node is null\n");
		return;
	}else if(node->elem == NULL){
		my_str("elem is null\n");
		return;
	}
	my_char(*(char*)node->elem);
	my_char('\n');
}
