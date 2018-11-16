CC=gcc
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 -L../../lib -lmy
DEPS = ../../include/list.h
IDIR = -I../../include/
OBJS = $(SRCS:.c=.o)

.PHONY: clean all fclean re


all: $(OBJS)
	$(CC) -o pipes pipes.c  $(CFLAGS)
	
clean:
	rm -f *.o

fclean: clean
	rm -f pipes 

re: fclean all
