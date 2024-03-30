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
        printf ("%'.6f\n",
            1 / (
                2 * M_PI * atof(argv[1]) * atof(argv[2]) *
                10e-7
                )
            );
        return (0);
    }
    else
    {
        puts ("rcfilt is an RC filter calculator.");
        puts ("output is cutoff frequency in Hz or desired component value\n");
        puts ("Usage: rcfilt param1 param2");
        puts ("param{1, 2} are two known parameters such as cutoff frequency and ohms or \
            ohms and microfarads. rcfilt will find the missing third parameter.\n");
        puts ("Example 1: rcfilt 15000 0.01 (resistance and microfarads)");
        puts ("Output should be: 1,061.032954 (cutoff frequency)\n");
        puts ("Example 2: rcfilt 1061.33 15000     (desired cutoff frequency(Hz) and ohms)");
        puts ("Output should be: 0.009997          (capacitance in microfarads)");
        return (1);
    }
}
