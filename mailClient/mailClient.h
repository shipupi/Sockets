#ifndef MAILCIENT_H
#define MAILCIENT_H

typedef struct mail {
	char * headers;
	char * message;
} Mail;


enum sizeConstants {
  MAXSTRINGLENGTH = 128,
  BUFSIZE = 512,
};

enum popConstants {
	POPDEFAULTPORT = 110
};

#endif