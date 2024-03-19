#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <ctype.h>
#include <unistd.h>

int main(int argc, char* *argv){
  printf("Programme principal\n");
 
  parse(argc, argv);

  return 0;
}
