/*  The Lightning Stalker 2014
 */

#include "tankfreq.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int
tankfreq(int argc, char ** argv)
{
    char progname[] = "tankfreq";
    
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
        fprintf(stderr, "\n"
                "  %s is an LC tank resonance frequency calculator.\n"
                "  output is frequency in Hz\n"
                "\n"
                "  Usage: %s [microfarads] [microhenries]\n"
                "\n"
                "  Example:  $ %s 3.3 0.86207\n"
                "  Output should be: 94360.861\n",
                progname, progname, progname);
        putc('\n', stderr);
        return (EXIT_FAILURE);
    }
    return (EXIT_FAILURE); /* makes tc happy */
}
