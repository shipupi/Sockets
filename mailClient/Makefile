CC=gcc
CFLAGS = -Wall -I.
INC = ../libs/
deps = mailClient.h tcpConnect.h
objects = mailClient.o tcpConnect.o
target = mailClient


%.o: %.c $(deps)
	$(CC) -c -o $@ $< $(CFLAGS)

$(target): $(objects)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm $(objects)