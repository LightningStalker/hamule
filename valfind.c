/*
 * Find resistor values for LM317 using various criteria
 * The Lightning Stalker 2014
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    float V, Rone, Rtwo;
    
    if (argc == 3)
    {
        V = atof(argv[1]);
        Rtwo = atof(argv[2]);
        Rone = Rtwo / (((V - (Rtwo * 0.0001)) / 1.25) - 1);
        printf("R1 shall be %fΩ\n", Rone);
    }
    else
    {
        puts("valfind is an LM317 resistor calculator.\n");
        puts("Usage: valfind Vout R2");
        puts("Where Vout is the desired output voltage and");
        puts("R2 is the desired resistance of R2.\n");
        puts("Example: valfind 4.2 1500");
        puts("Output should be 669.642883Ω");
        return(1);
    }
    
    return(0);
}
