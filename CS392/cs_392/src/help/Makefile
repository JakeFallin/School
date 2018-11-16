CC=gcc
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 -L../../lib -lmy -llist -lncurses
DEPS = ../../include/list.h
IDIR = ../../include/
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: clean all fclean re


all: 
	$(CC) -o nsminishell  $(SRCS) $(CFLAGS)
	
clean:
	rm -f *.o

fclean: clean
	rm -f nsminishell

re: fclean all
