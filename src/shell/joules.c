/* Project Crew™ 2023/12/14
*/

#define PROGNAME "joules"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int joules (int argc, char **argv)
{
    if (argc == 3)
    {
#if defined (__GNUC__)
        printf ("%'.3f\n", 5e-7 * atof(argv[1]) * \
            powf(atof(argv[2]), 2));
#elif defined (__WATCOMC__)
        printf ("%.3f\n", 5e-7 * atof(argv[1]) * \
            pow(atof(argv[2]), 2));
#else
        printf ("%.3f\n", 5e-7 * atof(argv[1]) * \
            powf(atof(argv[2]), 2));
#endif
        return (0);
    }
    else
    {
        fputs("\n"
              "  "PROGNAME" is a simple capacitor joule calculator\n"
              "  output is stored energy in joules\n"
              "\n"
              "  Usage: "PROGNAME" microfarads volts\n"
              "  Example:  $ "PROGNAME" 33 330\n"
              "  Output should be: 1.797\n",
              stderr);
        putc('\n', stderr);
        return (1);
    }
}

#undef  PROGNAME
