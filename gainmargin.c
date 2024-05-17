/* Compile with gcc -Wall -o gainmargin gainmargin.c -lm
    From STMicroelectronics AN2867 Rev 20 p.13
    Project Crew 2024 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <fenv.h>

int main (int argc, char **argv)
{
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping

    if (argc == 5)
    {
        printf ("%'.5LfmA/V\n",
                4e3 * atoll(argv[3]) *
                powl(2 * M_PI * atoll(argv[4]) * 1e6, 2) *
                powl((atoll(argv[1]) + atoll(argv[2])) * 1e-12, 2)
            );
        return (0);
    }
    else
    {
        puts ("gainmargin is a critical gain margin calculator for crystal oscillators.");
        puts ("output is gₘcrit in mA/V");
        puts ("");
        puts ("Usage: gainmargin shunt_pF load_pF ESR MHz");
        puts ("Example: gainmargin 5.0 12.0 150.0 12.0");
        puts ("Output should be: 0.98576mA/V");
    }
}
