#ifndef __PARSE_H__
#define __PARSE_H__
#include <argp.h>

int parse(int argc, char* *argv);

#define INET_ADDRSTRLEN 3000

struct arguments
{
    char host[INET_ADDRSTRLEN];
    int version;
    char file_to_output[30];
};

struct argp_option options[] = {
    {"target", 't', "HOST", 0, "Cible du scan" },
    {"output", 'o', "FILE",  0, "Fichier d'output" },
    {"version", 'v',  0, 0, "Affiche la version et quitte"},
    {"UDP scan", 'u', 0, 0, "Lance un scan UDP"},
    {"TCP scan", 't', 0, 0, "Lance un scan TCP"},
    { 0 }
};

#endif
