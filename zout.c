/* Compile with gcc -Wall -o zout zout.c
    The Lightning Stalker 2022 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 5)
    {
        double R1 = atof(argv[1]);
        double R2 = atof(argv[2]);
        double V1 = atof(argv[3]);
        double V2 = atof(argv[4]);

        printf ("%f\n", ((R1 - (R1 * V1 / V2)) / ((V1 / V2) - (R1 / R2))));
        return (0);
    }
    else
    {
        puts ("zout is an amplifier output impedance calculator.");
        puts ("output is impedance in Ohms\n");
        puts ("Usage: zout resistor1 resistor2 voltage1 voltage2");
        puts ("Example: zout 10000 1000 4.6 4.4");
        puts ("Output should be: 50.761421");
        return (1);
    }
}
