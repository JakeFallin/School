SERVERNAME = server
CLIENTNAME = client
SERVERSRC = server.c
CLIENTSRC = client.c
SERVEROBJS = $(SERVERSRC:.c=.o)
CLIENTOBJS = $(CLIENTSRC:.c=.o)

CFLAGS = -I../../include --pedantic  -Wall -Werror  
LDFLAGS = -C

all: server client

server: CFLAGS += -DSERVER
server: $(SERVEROBJS)
	cc -I../../include -L../../lib $(SERVEROBJS) -lmylist -lmy -o $(SERVERNAME)

client: $(CLIENTOBJS)
	cc -I../../include -L../../lib $(CLIENTOBJS) -lmy -o $(CLIENTNAME)

clean:
	rm -f $(SERVEROBJS)
	rm -f $(CLIENTOBJS)

fclean: clean
	rm -f $(SERVERNAME)
	rm -f $(CLIENTNAME)

re: fclean all