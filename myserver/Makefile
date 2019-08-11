CC=gcc
CFLAGS = -Wall -I.
deps = myserver.h
objects = myserver.o
target = myserver


%.o: %.c $(deps)
	$(CC) -c -o $@ $< $(CFLAGS)

$(target): $(objects)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm $(objects)