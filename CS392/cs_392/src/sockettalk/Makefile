CC=gcc
CFLAGS= -I../../include -Wall -Werror  --pedantic -std=c99 -mmacosx-version-min=10.6
DEPS = 
IDIR = 
OBJS = $(SRCS:.c=.o)

.PHONY: clean all fclean re


all: 
	$(CC) -o client client.c  $(CFLAGS)
	$(CC) -o server server.c  $(CFLAGS)
	
clean:
	rm -f *.o

fclean: clean
	rm -f client
	rm -f server

re: fclean all
