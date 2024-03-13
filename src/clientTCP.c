#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
struct sockaddr_in  serv_addr;

int stop = 0;

void handle_sigstp(int signum) {
    stop = 1;
}

int main(int argc, char* *argv){


  // Création de la socket
  int sockfd;

  if((sockfd = socket(PF_INET, SOCK_STREAM, 0))<0){
    perror("erreur client: erreur socket\n");
    exit(1);
  }


  // Demande de connexion
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons((ushort) atoi(argv[2]));
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
    perror("erreur client: erreur connect\n");
    exit(1);
  }


  char buffer[1024];
  int bytes_received;

  if ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) < 0) {
    perror("erreur client: erreur reception de données\n");
    exit(1);
  }

  buffer[bytes_received] = '\0';

  printf("[server] %s\n", buffer);

  char toSend[BUFFER_SIZE];

  printf(">>> ");
  fgets(toSend, sizeof(toSend), stdin);
  int message_len = strlen(toSend);
  
  if (send(sockfd, toSend, message_len, 0) != message_len) {
    perror("erreur serveur: erreur envoi de données\n");
    exit(1);
  }

  signal(SIGTSTP, handle_sigstp);

  while(!stop){
    char buffer[1024];
    int bytes_received;

    if ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) < 0) {
      perror("erreur client: erreur reception de données\n");
      exit(1);
    }

    buffer[bytes_received] = '\0';

    printf("[serveur] %s\n", buffer);

    char toSend[BUFFER_SIZE];

    printf(">>> ");
    fgets(toSend, sizeof(toSend), stdin);
    int message_len = strlen(toSend);

    if (send(sockfd, toSend, message_len, 0) != message_len) {
      perror("erreur client: erreur envoi de données\n");
      exit(1);
    }


  }




  close(sockfd);

  return 0;
}

