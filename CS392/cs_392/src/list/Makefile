CC=gcc
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 
TESTFLAGS = -L../../lib -llist -lmy
DEPS = ../../include/list.h
IDIR = ../../include/
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBLOC = ../../lib/liblist.a

.PHONY: clean all fclean re


all: $(OBJS)
	ar -rc $(LIBLOC) $(OBJS)
	ranlib $(LIBLOC)

test: re
	$(CC) -o $@ ../../test/testlist.c $(CFLAGS) $(TESTFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f test

re: fclean all
