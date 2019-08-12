#include "myserver.h"

#define MAX 80 
#define PORTNUMBER 995

#define SA struct sockaddr 

// Function designed for chat between client and server. 
void handleclient(int sockfd) 
{
    close(sockfd);    
     
} 
  
// Driver function 
int main() 
{ 
    printf("Here we go...\n");
    int sockfd, connfd;
    socklen_t len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 
    
    in_port_t port = PORTNUMBER;
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(port); 
    printf("Creating port %d\n", port);
    // Binding newly created socket to given IP and verification 
    // int one = 1;
    // setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    int bindAns;
    if ((bindAns = bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) < 0) { 
        printf("socket bind failed... %d \n", bindAns); 
        perror("Oh dear, something went wrong with read()!");

        exit(0); 
    } 
    printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    
    printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (struct sockaddr *)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    printf("Client connected!\n");
    // Function for chatting between client and server 
    handleclient(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
}
