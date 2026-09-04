/* Compile with gcc -o valfind valfind.c
 *
 * Find resistor values for LM317 using various criteria
 * The Lightning Stalker 2014
 */

#include <stdio.h>
#include <stdlib.h>

#if defined (__DOS__)
#define OMEGA   "\xea"
#else
#define OMEGA   "\u2126"                     /* differences of the codepage */
#endif


int main (int argc, char **argv)
{
    float V, Rone, Rtwo;

    if (argc == 3)
    {
        V = atof(argv[1]);
        Rtwo = atof(argv[2]);
        Rone = Rtwo / (0.8 * (V - 1e-4 * Rtwo) - 1);
        printf("R1 shall be %.3f"OMEGA"\n", Rone);
    }
    else
    {
        fputs("\n"
              "  valfind is an LM317 (and similar) resistor calculator.\n"
              "\n"
              "  Usage: valfind Vout R2\n"
              "  Where Vout is the desired output voltage and\n"
              "  R2 is the desired resistance of R2.\n"
              "\n"
              "  Example: valfind 4.2 1500\n"
              "  Output should be 669.643"OMEGA"\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
        return(1);
    }

    return(0);
}
