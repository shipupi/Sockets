#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "mailClient.h"
#include "popClient.h"
#include "../libs/tcpClient.h"
#include "../libs/utils.h"


// Strings - Where should these go?
const char* const SUCCESS_MSG = "+OK";


int main(int argc, char const *argv[]) {
	listMails();
	return 0;
}