#ifndef __PARSE_H__
#define __PARSE_H__
#include <argp.h>

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
    { 0 }
};

#endif
