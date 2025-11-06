/* Compile with gcc -Wall -o joules joules.c -lm
    The Lightning Stalker 2023/12/14 */

#define PROGNAME "joules"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined (__GNUC__)
#include <locale.h>
#endif

int main (int argc, char **argv)
{
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#endif

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
        puts ( \
            "\n"
            "  "PROGNAME" is a simple capacitor joule calculator\n"
            "  output is stored energy in joules\n"
            "\n"
            "  Usage: "PROGNAME" microfarads volts\n"
            "  Example: "PROGNAME" 33 330\n"
            "  Output should be: 1.797\n"
             );
        return (1);
    }
}
