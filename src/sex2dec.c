/* Compile with gcc -o sex2dec sex2dec.c */

#define PROGNAME    "sex2dec"

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 5)
    {
        printf ("%f\n", atoi(argv[1])
            + atoi(argv[2]) / 60.0
            + atoi(argv[3]) / 3600.0
            + atoi(argv[4]) / 216000.0);
        return (EXIT_SUCCESS);
    }else if (argc == 3)
    {
        printf ("%f\n", atoi(argv[1])
            + atof(argv[2]) / 60.0);
        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" is a sexagesimal (base 60) to decimal converter.\n"
              "  "PROGNAME" converts sexagesimal based deg/m/s/mils or deg/m.mmm coordinates into\n"
              "    decimal.\n"
              "  use ABSOLUTE VALUE of any negative number, and garbage in = garbage out\n"
              "  output is the coordinates in base 10\n"
              "  "PROGNAME" is not sexy.\n"
              "\n"
              "  Usage: "PROGNAME" degrees minutes seconds milliseconds\n"
              "     Or: "PROGNAME" degrees minutes.fraction\n"
              "  Example: "PROGNAME" 43 55 23 0\n"
              "  Output should be: 43.923056\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
        return (EXIT_FAILURE);
    }
}
