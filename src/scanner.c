#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int scan_tcp(int debut, int fin){
  printf("[-] Starting TCP scan");
  return 0;
}

int scan_udp(int debut, int fin){
  printf("[-] Starting UDP scan");
  return 0;
}

int scan(int scan_type, int debut, int fin){

  int result;

  if (scan_type){
    result = scan_udp(debut, fin);
  } else {
    result = scan_tcp(debut, fin);
  }
  return result;
}

