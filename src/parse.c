#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "scan.h"


int
parse(int argc, char **argv)
{
  int scan_type = 0;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "tu")) != -1)
    switch (c)
      {
      case 't':
        scan_type = 0;
        break;
      case 'u':
        scan_type = 1;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf(stderr, "unknown option `-%c'.\n", optopt);
        else
          fprintf(stderr, "unknown option character `\\x%x'.\n", optopt);
        return 1;
      default:
        abort ();
      }

  scan(scan_type, 0, 1); 

  return 0;
}

/*
int
main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = null;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("non-option argument %s\n", argv[index]);
  return 0;
}
*/
