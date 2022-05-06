/* Compile with gcc -Wall -o clod clod.c -lm
     Base loaded antenna loading coil calculator
     a very small program by The Lightning Stalker  April 14, 2022CE
     Formula sourced ARRL Handbook 2020 Edition Vol. 4. page 21.42*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 4)
    { // This is where it happens.
        float f = atof(argv[1]);             // frequency
        float h = atof(argv[2]);             // conductor height without coil
        float r = atof(argv[3]) / 2000;      // conductor radius in meters

        float den1 = logl(h / r) - 1;        // Japanese intermediate variables?
        float den2 = 1 - pow(f * h / 75, 2);

        float C = 55.78 * h / (den1 * den2); // capacitance of a small antenna

        float w = 2 * M_PI * f;              // angular frequency
        float L = 1 / (C * 1e-6 * w) / w;    // capacitance to inductance

        printf ("%.3fµH\n", L);
        return (0);
    }
    else
    {
        puts ("clod is a base loaded antenna loading coil calculator.");
        puts ("output is coil inductance in microhenries\n");

        puts ("Usage: clod frequency(MHz) whip_length(m) whip_diameter(mm)");
        puts ("Example: clod 10.000 1.7 10.0");
        puts ("Output should be: 12.237µH");
        return (1);
    }
}
