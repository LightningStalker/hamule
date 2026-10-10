/* Toroid capacitance
 * Original work by Herbert Mehlhose 4/2000 and others
 *
 * Project Crew™ 10/9/2026
 */

#define PROGNAME    "ctor"

#include <stdio.h>
#include <stdlib.h>

#define SQRTPI  1.77245385090551599275
#define X28RPI  2.8 * SQRTPI
#define X       0.2909
#define RXMX2   0.45417748733287078147       /* sqrt(X - X ^ 2) */

void
usage()
{
    fputs("\n  "
         PROGNAME" is a toroid capacitance calculator.\n"
         "  The d\u2081:d\u2082 best ratio is 0.2909.\n"
         "  Give me the outer diameter in millimeters I can find the capacitance and the\n"
         "    height using the 0.2909 ratio.\n"
         "\n"
         "  Usage: "PROGNAME" [outer diameter in mm]\n"
         "\n"
         "  Example:  $ "PROGNAME" 500\n"
         "  Output should be: 21.901 pF, 145.450 mm\n",
         stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
    exit(EXIT_FAILURE);
}


int
main(int argc, char *argv[])
{
    int t = 0;
    double d_1, d_2, a, C;

    if(argc == 2)
    {
        while(argv[1][t] != 0)               /* check for invalid chars */
        {
            if(argv[1][t] > '9' || argv[1][t] < '.') usage();
            t++;
        }
        d_1 = atof(argv[1]);
        d_2 = d_1 * X;                       /* d_2 is always d_1 * X */

        a = X28RPI * d_1 / 50.8;
        C = (a * 1.2781 - a * X) * RXMX2;

        printf("C  = %.3f pF\n"
               "d\u2082 = %.3f mm\n", C, d_2);
    }else
    {
        usage();
    }
    return (EXIT_FAILURE);
}
