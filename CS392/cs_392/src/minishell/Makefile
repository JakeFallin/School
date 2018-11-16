CC=gcc
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 -L../../lib -lmy
DEPS = ../../include/my.h
IDIR = ../../include/
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: clean all fclean re


all: 
	$(CC) -o minishell  $(SRCS) $(CFLAGS)
	
clean:
	rm -f *.o

fclean: clean
	rm -f minishell

re: fclean all
