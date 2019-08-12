#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "../libs/tcpClient.h"
#include <string.h>


int main(int argc, char const *argv[])
{
	int sock;
	tcpConnect("127.0.01", 110, &sock);

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

int login(char * user, char * passwd, int sock) {
	char * userMsg;
	char * passwdMsg;
	generateLoginStrings(userMsg,passwdMsg,user,passwd);
	
	ssize_t numBytes = send(sock, userMsg, userLen, 0);
	if (!successfulUser(numBytes,sock)) {
		perror("Invalid username");
		exit(1);
	}

	ssize_t numBytes = send(sock, user, userLen, 0);

}
void generateLoginStrings(char * userMsg, char *passwdMsg, user, passwd) {
	// Generate user and password strings
	char *userBase = "user ";
	int userLen = strlen(userBase) + strlen(user);
	*userMsg = malloc(1+userLen);
	strcpy(userMsg, userBase);
	strcat(userMsg, user);

	char *passwdBase = "pass ";
	int passwdLen = strlen(passwdBase) + strlen(passwd);
	*passwdMsg = malloc(1+passwdLen);
	strcpy(passwdMsg, passwdBase);
	strcat(passwdMsg, passwd);
}