#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERV_PORT 2222 
#define BUFFER_SIZE 1024
struct sockaddr_in  serv_addr;

int stop = 0;

void handle_sigstp(int signum) {
    stop = 1;
}

int main(int argc, char* *argv){


  //Ouverture de la socket
  int serverSocket;

  if((serverSocket = socket(PF_INET, SOCK_STREAM, 0))<0){
    perror("erreur serveur: erreur socket\n");
    exit(1);
  }


  // On bind la socket
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(SERV_PORT);

  if(bind(serverSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
    perror("erreur serveur: erreur bind.\n");
    exit(1);
  }


  // On écoute
  if(listen(serverSocket, SOMAXCONN)<0){
    perror("erreur serveur: erreur listen\n");
    exit(1);
  }


  // Création de la socket de dialogue
  int dialogSocket;
  int clilen;
  struct sockaddr_in cli_addr;

  clilen = sizeof(cli_addr);
  dialogSocket = accept(serverSocket, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);

  if(dialogSocket<0){
    perror("erreur serveur: erreur d'accept");
    exit(1);
  }

  char *message = "Bonjour!\n";
  int message_len = strlen(message);
  
  if (send(dialogSocket, message, message_len, 0) != message_len) {
    perror("erreur serveur: erreur envoi de données\n");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  int bytes_received;

  if ((bytes_received = recv(dialogSocket, buffer, sizeof(buffer), 0)) < 0) {
    perror("erreur client: erreur reception de données\n");
    exit(1);
  }

  buffer[bytes_received] = '\0';

  printf("[client] %s\n", buffer);

  signal(SIGTSTP, handle_sigstp);

  while(!stop){
    char toSend[BUFFER_SIZE];

    printf(">>> ");
    fgets(toSend, sizeof(toSend), stdin);
    int message_len = strlen(toSend);

    if (send(dialogSocket, toSend, message_len, 0) != message_len) {
      perror("erreur serveur: erreur envoi de données\n");
      exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    if ((bytes_received = recv(dialogSocket, buffer, sizeof(buffer), 0)) < 0) {
      perror("erreur serveur: erreur reception de données\n");
      exit(1);
    }

    buffer[bytes_received] = '\0';

    printf("[client] %s\n", buffer);
  }


  // Fermeture de la socket de dialogue
  close(dialogSocket);
  

  // Fermeture de la socket d'écoute
  close(serverSocket);
}

