/* Compile with gcc -Wall -o clod clod.c -lm
     Antenna loading coil calculator
     a very small program by The Lightning Stalker  May 5, 2022CE
     Formula sourced from Off-Center Loaded Dipole Antennas, QST magazine,
     September, 1974, courtesy WC2L and M0UKD */

#define PROGNAME "clod"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI     3.14159265358979323846  /* pi */
#endif
#endif

#if defined (__DOS__)
#define MUSYM    "\xe6"
#else
#define MUSYM    "µ"  /* differences of the codepage */
#endif


int main (int argc, char **argv)
{
    float den1,
          den2,
          den3,
          den4,
          L;
    
    if (argc == 5) // stupid input = stupid output
    { // metric-imperial conversion
        float f = atof(argv[1]);          // frequency in Megahertz
        float l = atof(argv[2]) / 0.3048; // overall antenna length
        float D = atof(argv[3]) / 0.3048; // distance from feed point to coil
        float d = atof(argv[4]) / 25.4;   // diameter of radiating element or whip

#if defined (__WATCOMC__)
        den1 = log(24 * ((234 / f) - D) / d) - 1;
        den2 = pow(1 - (f * D / 234), 2) - 1;
#elif defined (__GNUC__)
        den1 = logf(24 * ((234 / f) - D) / d) - 1;
        den2 = powf(1 - (f * D / 234), 2) - 1;
#endif
        den3 = (den1 * den2) / (234 / f - D);

#if defined (__WATCOMC__)
        den1 = log(24 * (l - D) / d) - 1; // Japanese intermediate variables?
        den2 = pow((((f * l) - f * D) / 234), 2) - 1;
#elif defined (__GNUC__)
        den1 = logf(24 * (l - D) / d) - 1; // Japanese intermediate variables?
        den2 = powf((((f * l) - f * D) / 234), 2) - 1;
#endif
        den4 = den3 - ((den1 * den2) / (l - D));

        // inductance of loading coil
        L = 1e6 / (68 * (M_PI * M_PI) * (f * f)) * den4;
        // Things may get a little weird if the coil is too close to the end.
        printf ("%.3f"MUSYM"H\n", L);
        return (0);
    }
    else
    {
        puts ("\n"
              "  "PROGNAME" is an antenna loading coil calculator.\n"
              "  output is coil inductance in microhenries\n"
              "\n"
              "  Usage: "PROGNAME" frequency(MHz) whip_length(m) coil_position(m) whip_diameter(mm)\n"
              "  Example: "PROGNAME" 7.105 2.2 1.1 5.0\n"
              "  Output should be: 39.606"MUSYM"H\n");
              
        return (1);
    }
}
