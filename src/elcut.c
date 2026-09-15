/* Compile with gcc -o elcut elcut.c
    The Lightning Stalker August 28, 2019 */

#define PROGNAME "elcut"

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
        fputs("\n"
              "  "PROGNAME" is a resonant antenna tuning aid.\n"
              "  "PROGNAME" finds the length to cut based on the current and desired frequency.\n"
              "\n"
              "  output is the length of an ideal cutoff\n"
              "  remember the output is theoretical and subtract from it to avoid mistuning.\n"
              "\n"
              "  Usage: "PROGNAME" freq_desired freq_current length_current\n"
              "  Example: "PROGNAME" 28.33 25.55 2516\n"
              "  Output should be: 246.893046\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
        return (1);
    }
}
