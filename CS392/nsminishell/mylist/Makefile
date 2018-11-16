#Makefile for libmylist.a
NAME=libmylist.a
SRC=add_elem.c add_node_at.c add_node.c append.c count_nodes.c elem_at.c empty_list.c new_node.c node_at.c remove_last.c remove_node_at.c remove_node.c traverse_char.c traverse_int.c traverse_string.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../lib
#
TESTSRC=../test/mylisttest.c
TESTOBJ=$(TESTSRC:.c=.o)
TESTNAME= listtest
LIBS=-lmylist -lmy
# Begin Commands
all:$(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all

test: $(TESTOBJ)
	cc -L$(LIBPATH) $(TESTOBJ) $(LIBS) -o $(TESTNAME)

ret: re test