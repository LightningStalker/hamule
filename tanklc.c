/* Compile with gcc -Wall -o tanklc tanklc.c -lm
    The Lightning Stalker ~2015 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (int argc, char **argv)
{
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping

    if (argc == 3)
    {
        printf ("%'.9f\n",
            pow(1 /
            atof(argv[1]) / (2 * M_PI), 2) /
            atof(argv[2]) * 10e5
            );
        return (0);
    }
    else
    {
        puts ("tanklc finds the value of L or C given fres and either L or C.");
        puts ("output is value in microhenries or microfarads\n");
        puts ("Usage: tanklc fres(kHz) {L,C}(µH,µF)");
        puts ("Example: tanklc 300.000 38");
        puts ("Output should be: 0.007406519");
        return (1);
    }
}
