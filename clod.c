/* Compile with gcc -Wall -o clod clod.c -lm
     Antenna loading coil calculator
     a very small program by The Lightning Stalker  May 5, 2022CE
     Formula sourced from Off-Center Loaded Dipole Antennas, QST magazine,
     September, 1974, courtesy WC2L and M0UKD */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 5) // stupid input = stupid output
    { // metric-imperial conversion
        float f = atof(argv[1]);          // frequency in Megahertz
        float l = atof(argv[2]) / 0.3048; // overall antenna length
        float D = atof(argv[3]) / 0.3048; // distance from feed point to coil
        float d = atof(argv[4]) / 25.4;   // diameter of radiating element or whip

        float den1 = logl(24 * ((234 / f) - D) / d) - 1;
        float den2 = pow(1 - (f * D / 234), 2) - 1;
        float den3 = (den1 * den2) / (234 / f - D);

        den1 = logl(24 * (l - D) / d) - 1; // Japanese intermediate variables?
        den2 = pow((((f * l) - f * D) / 234), 2) - 1;
        float den4 = den3 - ((den1 * den2) / (l - D));

        // inductance of loading coil
        float L = 1e6 / (68 * (M_PI * M_PI) * (f * f)) * den4;
        // Things may get a little weird if the coil is too close to the end.
        printf ("%.3fµH\n", L);
        return (0);
    }
    else
    {
        puts ("clod is an antenna loading coil calculator.");
        puts ("output is coil inductance in microhenries\n");

        puts ("Usage: clod frequency(MHz) whip_length(m) coil_position(m) whip_diameter(mm)");
        puts ("Example: clod 7.105 2.2 1.1 5.0");
        puts ("Output should be: 39.606µH");
        return (1);
    }
}
