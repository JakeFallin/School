CC=gcc
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 -L../../lib -lmy -L../../lib -llist -lncurses
DEPS = ../../include/my.h
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
