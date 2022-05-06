/* Compile with gcc -Wall -o tanklc tanklc.c -lm
    The Lightning Stalker ~2015 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        printf ("%f\n", pow(1 / atof(argv[1]) / 6.28318530717958648, 2) /
                atof(argv[2]) * pow(10,6));
        return (0);
    }
    else
    {
        puts ("tanklc finds the value of L or C given fres and either L or C.");
        puts ("output is value in microhenries or microfarads\n");
        puts ("Usage: tanklc fres(kHz) {L,C}(µH,µF)");
        puts ("Example: tanklc 300.000 38");
        puts ("Output should be: 0.007407");
        return (1);
    }
}
