CC=gcc
CFLAGS = -Wall -I.
DEPS= mailClient.h popClient.h 
OBJ= mailClient.o  popClient.o
LIBS = ../libs/*.c
LIBSH = ../libs/*.h

mailClient.protos: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJ): $(OBJ:.o=.c) $(DEPS) $(LIBSH) $(LIBS) 
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c)

clean:
	rm -rf $(OBJ)
