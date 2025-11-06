/* Compile with gcc -Wall -o rcfilt rcfilt.c -lm
    The Lightning Stalker 2024 */

#define PROGNAME "rcfilt"

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
int main (int argc, char **argv)
{
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#endif

    if (argc == 3)
    {
#if defined (__WATCOMC__)
        printf ("%.6f\n",
            1 / (
                2 * M_PI * atof(argv[1]) * atof(argv[2]) *
                1e-6
                )
            );
#elif defined (__GNUC__)
       printf ("%'.6f\n",
            1 / (
                2 * M_PI * atof(argv[1]) * atof(argv[2]) *
                1e-6
                )
            );
#endif
        return (0);
    }
    else
    {
        puts ( \
            "\n"
            "  "PROGNAME" is an RC filter calculator.\n"
            "  output is cutoff frequency in Hz or desired component value\n"
            "\n"
            "  Usage: "PROGNAME" param1 param2\n"
            "  param{1, 2} are two known parameters such as cutoff frequency and ohms or\n"
            "        ohms and microfarads. rcfilt will find the missing third parameter.\n"
            "\n"
            "  Example 1: "PROGNAME" 15000 0.01 (resistance and microfarads)\n"
            "  Output should be: 1,061.032954 (cutoff frequency)\n"
            "\n"
            "  Example 2: "PROGNAME" 1061.33 15000     (desired cutoff frequency(Hz) and ohms)\n"
            "  Output should be: 0.009997          (capacitance in microfarads)\n"
        );
        return (1);
    }
}
