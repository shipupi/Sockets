#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
	int sock;
	// tcpConnect("127.0.01", 110, &sock);
	sock = 2;
	char buffer[1000];
	ssize_t numBytes;
	numBytes = recv(sock, buffer, 999, 0);
	if (numBytes < 0) {
		fprintf(stderr, "Error on recv\n");
		exit(1);
	}
	printf("Received: %s\n", buffer);
	close(sock);
	return 0;
}