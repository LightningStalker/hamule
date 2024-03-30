/* Compile with gcc -Wall -o tankfreq tankfreq.c -lm
    The Lightning Stalker 2014 */

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
        printf ("%'.3f\n",
            1 / (
            2 * M_PI * sqrt (
                atof(argv[1]) * atof(argv[2]) * 10e-13
                )
            )
        );
        return (0);
    }
    else
    {
        puts ("tankfreq is an LC tank resonance frequency calculator.");
        puts ("output is frequency in Hz\n");
        puts ("Usage: tankfreq microfarads microhenries");
        puts ("Example: tankfreq 3.3 0.86207");
        puts ("Output should be: 94,360.861");
        return (1);
    }
}
