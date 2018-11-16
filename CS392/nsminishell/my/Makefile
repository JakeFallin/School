#Makefile for libmy.a
NAME=libmy.a
SRC=my_alpha.c my_char.c my_digits.c my_find.c my_int.c my_num_base.c my_revstr.c my_rfind.c my_stdstrnconcat.c my_str.c my_strcat.c my_strcmp.c my_vect2str.c my_strconcat.c my_strcpy.c my_strdup.c my_strindex.c my_strlen.c my_strncmp.c my_strnconcat.c my_strncpy.c my_strrindex.c xmalloc.c my_str2vect.c my_printvect.c my_stripbuffer.c my_atoi.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../lib
#
TESTSRC=../test/mytest.c
TESTOBJ=$(TESTSRC:.c=.o)
TESTNAME= mytest
LIBS=-lmy
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