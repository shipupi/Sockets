#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int tcpConnect(char *ip, int portInt, int *sock) {

	in_port_t port = (in_port_t) portInt;
	
	*(sock) = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0) {
		fprintf(stderr, "socket() fail\n");
		exit(1);	
	}

	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
	servAddr.sin_family = AF_INET;          // IPv4 address family
	// Convert address
	int rtnVal = inet_pton(AF_INET, ip, &servAddr.sin_addr.s_addr);
	if (rtnVal == 0){
	    fprintf(stderr, "inet_pton() failed\n");
	    exit(1);
	} else if (rtnVal < 0) {
	    fprintf(stderr, "inet_pton() failed 2\n");
	    exit(1);
	}
	servAddr.sin_port = htons(port);    // Server port
	return 1;
}
