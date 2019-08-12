CC=gcc
CFLAGS= -Wall -Werror -std=c99
DEPS= myserver.h
OBJ= myserver.o

myserver: $(OBJ)
	$(CC) $(CFLAGS) -o $(^:.o=.protos) $^

$(OBJ): $(OBJ:.o=.c) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.protos)

.PHONY: clean myserver

