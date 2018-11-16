TARGET = nsminishell
CFLAGS += -I../../include -g -std=c99 -Wall -Werror -pedantic
LDFLAGS += -L../../lib
LDLIBS += -llist -lmy -lncurses

all: $(TARGET)

clean:
	$(RM) $(TARGET)

fclean: clean

re: fclean all