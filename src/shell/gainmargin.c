/*  From STMicroelectronics AN2867 Rev 20 p.13
 *
 *   Project Crew 2024
 */

#define PROGNAME "gainmargin"

#include <math.h>

#include "gainmargin.h"
#include "define.h"
#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#if defined (__GNUC__)
#include <locale.h>
#endif


int gainmargin (int argc, char **argv)
{
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#endif

    if (argc == 5)
    {
#if defined (__WATCOMC__)
        printf ("%.5LfmA/V\n",
                4e3 * atoll(argv[3]) *
                pow(2 * M_PI * atoll(argv[4]) * 1e6, 2) *
                pow((atoll(argv[1]) + atoll(argv[2])) * 1e-12, 2)
            );
#elif defined (__GNUC__)
        printf ("%'.5LfmA/V\n",
                4e3 * atoll(argv[3]) *
                powl(2 * M_PI * atoll(argv[4]) * 1e6, 2) *
                powl((atoll(argv[1]) + atoll(argv[2])) * 1e-12, 2)
            );
#endif
        return (EXIT_SUCCESS);
    }
    else
    {
        fputs("\n"
              "  "PROGNAME" is a critical gain margin calculator for crystal oscillators.\n"
              "  output is g"SUBM"crit in mA/V\n"
              "\n"
              "  Usage: "PROGNAME" shunt_pF load_pF ESR MHz\n"
              "  Example:  # "PROGNAME" 5.0 12.0 150.0 12.0\n"
              "  Output should be: 0.98576mA/V\n"
              "\n",
              stderr);
        return (EXIT_FAILURE);
    }
}

#undef  PROGNAME
