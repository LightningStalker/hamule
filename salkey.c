/* Compile with gcc -Wall -o salkey salkey.c -lm
 * sallen key filter cutoff frequency
 * https://en.wikipedia.org/wiki/Sallen–Key_topology
 * Project Crew™ 2024
 */

#define PROGNAME "salkey"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined (__GNUC__)
#include <locale.h>
#endif

#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
#endif
#endif


int
main(int argc, char ** argv)
{
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#endif

    float R,  /* resistor  R1 = R2 */
          C;  /* capacitor C1 = C2 */

    if (argc == 3)
    {
        R = atof(argv[1]);
        C = atof(argv[2]);

        R = R * R;
        C = C * C * 1e-12;

#if defined (__GNUC__)
        printf("%'.0f\n", \
               round(
                   1 /
                   ( 2 * M_PI * sqrt(R * C) )
                   )
              );
#elif defined (__WATCOMC__)
        printf("%.0f\n", \
                   1 /
                   ( 2 * M_PI * sqrt(R * C) )
              );
#else
        printf("%.0f\n", \
               round(
                   1 /
                   ( 2 * M_PI * sqrt(R * C) )
                   )
              );
#endif
        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" is a Sallen-Key filter cutoff frequency calculator.\n"
              "  of the type R1 = R2 = R\n"
              "              C1 = C2 = C\n"
              "  output is frequency in Hz\n"
              "\n"
              "  Usage: "PROGNAME" [R] [C] (microfarads)\n"
              "\n"
              "  Example:  $ "PROGNAME" 1000.0 0.01\n"
              "  Output should be: 15,915\n"
              "\n"
              "  (https://en.wikipedia.org/wiki/Sallen–Key_topology)\n"
              "\n", stderr);

        return (EXIT_FAILURE);
    }
}
