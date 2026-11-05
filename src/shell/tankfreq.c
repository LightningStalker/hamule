/*  The Lightning Stalker 2014
 */

#define PROGNAME    "tankfreq"

#include "tankfreq.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int
tankfreq(int argc, char ** argv)
{
    if (argc == 3)
    {
        printf("%'.3f\n",
                     1 /
                     (
                      2 * M_PI * sqrt( atof(argv[1]) * atof(argv[2]) )
                     ) * 1e6
              );
    }else
    {
        fputs("\n"
              "  "PROGNAME" is an LC tank resonance frequency calculator.\n"
              "  output is frequency in Hz\n"
              "\n"
              "  Usage: "PROGNAME" [microfarads] [microhenries]\n"
              "\n"
              "  Example:  $ "PROGNAME" 3.3 0.86207\n"
              "  Output should be: 94,360.861\n",
              stderr);
        putc('\n', stderr);
        return (EXIT_FAILURE);
    }
    return (EXIT_FAILURE); /* makes tc happy */
}

#undef  PROGNAME
