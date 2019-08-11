#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>

#define PORT 23423

#define PREGUNTA_0 "------------- DESAFIO -------------\nBienvenidos al TP4 y felicitaciones, ya resolvieron el primer acertijo.\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un servidor que se comporte igual que yo, además del cliente para comunicarse con el mismo.\n\nDeberán estar atentos a los desafios ocultos.\n\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con 'entendido\n'\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n"

#define PREGUNTA_1 "------------- DESAFIO -------------\n# \033[D \033[A \033[A \033[D \033[B \033[C \033[B \033[D *\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n"

#define PREGUNTA_2 "------------- DESAFIO -------------\nhttps://vocaroo.com/i/s19015zmR4t8\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n"

#define PREGUNTA_3 "------------- DESAFIO -------------\nEBADF... abrilo y verás\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n"

#define PREGUNTA_4 "------------- DESAFIO -------------\nrespuesta = strings[224]\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n"

#define PREGUNTA_5 "X\n"

#define RTA_1 "entendido\n"
#define RTA_2 "#0854780*\n"
#define RTA_3 "nokia\n"
#define RTA_4 "cabeza de calabaza\n"
#define RTA_5 "string\n"
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char * hello = "Hello from server"; 

    char * P_0 = PREGUNTA_0;
    char * P_1 = PREGUNTA_1;

    char * preguntas[10] = [P_0,P_1];
    char * respuestas[10] = [RTA_1,RTA_2,RTA_3,RTA_4,RTA_5];
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the PORT 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the PORT 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }

    int i = 0;

    while(1){

    valread = read( new_socket , buffer, 1024); 
    printf("1: %s\n",buffer );
    if(strcmp(respuestas[i],buffer)==0){
        printf("Respuesta Correcta\n");
        i++;
        printf(preguntas[i]);
    }
    else{
        printf("Respuesta Incorrecta\n");
    }

    }
    return 0; 
} 



