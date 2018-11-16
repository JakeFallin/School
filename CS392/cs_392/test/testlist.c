#include "../include/list.h"
#include "../include/my.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

int *makeint(int x){
	int *temp = malloc(sizeof(int));
	*temp = x;
	return temp;
}

int main(int argc, char const *argv[]){
	//struct s_node* n1 = new_node("ONE", NULL, NULL);
	//struct s_node* n2 = new_node("testingremove", NULL, NULL);
	struct s_node* head = new_node("dingus", NULL, NULL);
	struct s_node** header = NULL;
	//*header = NULL;

	my_str("testing append +++++++++++++++++++++++++++++++++++++++\n");
	append(new_node("appendnode", NULL, NULL), header);
	debug_string(head);
	//my_str("Current head node: "); print_string(*header);
	my_char('\n');
    
/*
	my_str("Testing add_node +++++++++++++++++++++++++++++++++++++++++++\n");
	add_node(new_node("add2", NULL, NULL), header);
	debug_string(*header);
	my_str("Current head node: "); print_string(*header);
	my_char('\n');

	my_str("testing add_elem +++++++++++++++++++++++++++++++++++++++\n");
	add_elem(NULL, header);
	add_elem("addelem", NULL);
	add_elem("addelem", header);
	debug_string(*header);
	my_str("Current head node: "); print_string(*header);
	my_char('\n');

	my_str("testing append +++++++++++++++++++++++++++++++++++++++\n");
	append(new_node("appendnode", NULL, NULL), header);
	debug_string(*header);
	my_str("Current head node: "); print_string(*header);
	my_char('\n');

	my_str("Testing add_node_at +++++++++++++++++++++++++++++++++++++++++\n");
	add_node_at(NULL, header, 3);
	add_node_at(new_node("addatnullhead", NULL, NULL), NULL, 2);
	add_node_at(n2, header, 3);
	add_node_at(new_node("addAt-1",NULL, NULL), header, -1);
	debug_string(*header);
	my_char('\n');

	my_str("Testing remove_node +++++++++++++++++++++++++++++++++++++++++\n");
	my_str(remove_node(&n2));my_char('\n');
	debug_string(*header);
	my_str("Current head node: "); print_string(*header);
	my_char('\n');

	my_str("Testing remove_last +++++++++++++++++++++++++++++++++++++++++\n");
	remove_last(header);
	debug_string(*header);
	my_str("Current head node: "); print_string(*header);
	my_char('\n');

	my_str("Testing count_s_nodes +++++++++++++++++++++++++++++++++++++++++\n");
	my_int(count_s_nodes(*header));my_char('\n');
	my_char('\n');


	my_str("Testing remove_node_at +++++++++++++++++++++++++++++++++++++++++\n");
	my_str(remove_node_at(header, -11));my_char('\n');
	debug_string(*header);
	my_char('\n');

	my_str("Testing elem_at +++++++++++++++++++++++++++++++++++++++++\n");
	my_str(elem_at(*header, 0));my_str(" zero\n");
	my_str(elem_at(*header, 1));my_str(" one \n");
	my_str(elem_at(*header, 33));my_str(" thirtythree\n");
	my_str(elem_at(*header, -1));my_str(" negone\n");
	my_str(elem_at(new_node(NULL,NULL,NULL),0));my_str(" null elem\n");
	my_char('\n');

	my_str("Testing node_at +++++++++++++++++++++++++++++++++++++++++\n");
	print_string(node_at(*header, 0));
	print_string(node_at(*header, -1));
	print_string(node_at(NULL, 0));
	print_string(node_at(*header, 30));
	print_string(node_at(new_node(NULL,NULL,NULL), 30));
	my_char('\n');

	my_str("Testing debug_* +++++++++++++++++++++++++++++++++++++++++\n");
	debug_string(*header);
	debug_char(*header);
	debug_int(*header);
	my_char('\n');

	my_str("Testing traverse_* +++++++++++++++++++++++++++++++++++++++++\n");
	traverse_char(*header);
	traverse_int(*header);
	traverse_string(*header);
	my_char('\n');

	my_str("Testing print_int ++++++++++++++++++++++++++++++++++++++++++\n");
	print_int(new_node(makeint(7),NULL,NULL));
	print_int(NULL);
	print_int(new_node(NULL,NULL,NULL));
	my_char('\n');

	my_str("Testing print_char +++++++++++++++++++++++++++++++++++++++++\n");		
	print_char(new_node(makeint('1'),NULL,NULL));
	my_char('\n');
	
	my_str("testing print_string +++++++++++++++++++++++++++++++++++++++\n");
	print_string(new_node("jjjjjjjjjjjj",NULL,NULL));
	my_char('\n');

	my_str("Testing empty_list +++++++++++++++++++++++++++++++++++++++++\n");
	empty_list(header);
	debug_string(*header);
	my_char('\n');










*/	
}
