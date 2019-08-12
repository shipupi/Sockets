CC=gcc
CFLAGS = -Wall -I.
#INC = ../libs/
DEPS= mailClient.h 
OBJ= mailClient.o 

mailclient: $(OBJ)
	$(CC) $(CFLAGS) -o $(^:.o=.protos) $^ ../libs/tcpClient.c

$(OBJ): $(OBJ:.o=.c) $($DEPS)
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.protos)
