/* Compile with gcc -Wall -o bclod bclod.c -lm
     Base loaded antenna loading coil calculator
     a very small program by The Lightning Stalker  April 14, 2022CE
     Formula sourced ARRL Handbook 2020 Edition Vol. 4. page 21.42 */

#define PROGNAME "bclod"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
#endif
#endif

#if defined (__DOS__)
#define MUSYM   "\xe6"
#else
#define MUSYM   "µ"                 /* differences of the codepage */
#endif


int main (int argc, char **argv)
{
    if (argc == 4)
    { // This is where it happens.
        float f = atof(argv[1]);             // frequency
        float h = atof(argv[2]);             // conductor height without coil
        float r = atof(argv[3]) / 2000;      // conductor radius in meters

#if defined (__WATCOMC__)
        float den1 = log(h / r) - 1;        // Japanese intermediate variables?
#else
        float den1 = logl(h / r) - 1;        // Japanese intermediate variables?
#endif
        float den2 = 1 - pow(f * h / 75, 2);

        float C = 55.78 * h / (den1 * den2); // capacitance of a small antenna

        float w = 2 * M_PI * f;              // angular frequency
        float L = 1 / (C * 1e-6 * w) / w;    // capacitance to inductance

        printf ("%.3f"MUSYM"H\n", L);
        return (0);
    }
    else
    {
        puts ( \
                "\n"
                "  "PROGNAME" is a base loaded antenna loading coil calculator.\n"
                "  output is coil inductance in microhenries\n"
                "\n"
                "  Usage:   "PROGNAME" frequency(MHz) whip_length(m) whip_diameter(mm)\n"
                "  Example: "PROGNAME" 10.000 1.7 10.0\n"
                "  Output should be: 12.237"MUSYM"H\n"
             );
        return (1);
    }
}
