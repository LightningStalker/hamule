/* Compile with gcc -Wall -o joules joules.c -lm
    The Lightning Stalker 2023/12/14 */

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
        printf ("%'.3f\n", 0.0000005 * atof(argv[1]) * \
            powf(atof(argv[2]), 2));
        return (0);
    }
    else
    {
        puts ("joules is a simple capacitor joule calculator.");
        puts ("output is stored energy in joules\n");
        puts ("Usage: joules microfarads volts");
        puts ("Example: joules 33 330");
        puts ("Output should be: 1.797");
        return (1);
    }
}
