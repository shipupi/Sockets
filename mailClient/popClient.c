#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "mailClient.h"
#include "popClient.h"
#include "../libs/tcpClient.h"
#include "../libs/utils.h"


#define SUCCESSMSG "+OK"
#define STATMSG "list"


int popConnect(char *ip, int portInt, int *sock) {
	tcpConnect(ip,portInt, sock);
	char buffer[BUFSIZE];
	ssize_t numBytes;
	numBytes = recv(*(sock), buffer, BUFSIZE, 0);
	if (numBytes < 0) {
		fprintf(stderr, "Error on recv\n");
		return -1;
	}
	if (!startsWith(buffer, SUCCESSMSG)) {
		fprintf(stderr, "Error connecting to socket: %s\n", buffer);
		return -1;
	}
	return 1;
}

int listMails() {
	int sock;
	if(popConnect("127.0.0.1", 110, &sock) < 0) {
		goto error;
	}
	printf("Pop connected succesfully :)\n");

	close(sock);
	return 1;

	error:
		printf("reached here (error)\n");
		close(sock);
		return 0;
}
