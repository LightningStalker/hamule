/* Compile with gcc -Wall -o elcut elcut.c */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 4)
    {
        printf ("%f\n", (atof(argv[1]) - atof(argv[2])) / atof(argv[1]) * atof(argv[3]));
        return (0);
    }
    else
    {
        puts ("elcut is a resonant antenna tuning aid.");
        puts ("elcut finds the length to cut based on the current and desired frequency.");
        puts ("output is the length of an ideal cutoff");
        puts ("remember the output is theoretical and subtract from it to avoid mistuning.\n");
        puts ("Usage: elcut freq_desired freq_current length_current");
        puts ("Example: elcut 28.33 25.55 2516");
        puts ("Output should be: 246.893046");
        return (1);
    }
}
