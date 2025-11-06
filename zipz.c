/* Compile with gcc -Wall -o zipz zipz.c -lm
    The Lightning Stalker 2024 */

#define PROGNAME "zipz"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#if defined (__GNUC__)
#include <locale.h>
#endif

#if defined (__DOS__)
#define OMEGA   "\xea"
#else
#define OMEGA   "Ω"                     /* differences of the codepage */
#endif


void
usage(void) {
    puts ( \
        "\n"
        "  "PROGNAME" calculates the impedance of open wire line and zip cord\n"
        "  and reverse calculation of conductor spacing\n"
        "  output is impedance in Ohms\n"
        "\n"
        "  Usage: "PROGNAME" distance radius k\n"
        "     or: "PROGNAME" -r impedance radius k\n"
        "  Distance is distance between centers of conductors\n"
        "  Radius is radius of one conductor\n"
        "  k is relative permittivity in region between conductors\n"
        "\n"
        "  Example 1: "PROGNAME" 35.5 1.25 1.0\n"
        "  Output should be: 401.1("OMEGA")\n"
        "\n"
        "  Example 2: "PROGNAME" -r 456.8 0.05 1.2\n"
        "  Output should be: 3.2510 (distance d)\n"
        );
          
    exit (EXIT_FAILURE);
}

void
calculate(float d, float r, float k) {
#if defined (__WATCOMC__)
    printf ("%.1f\n",
        276.0 /
        sqrt(k) *
        log10(d / r)
        );
#elif defined (__GNUC__)
    printf ("%'.1f\n",
        276.0 /
        sqrtf(k) *
        log10f(d / r)
        );
#endif
    return;
}

void
reverseCalc(float impedance, float r, float k) {
#if defined (__WATCOMC__)
    printf("%.4f\n",
        r *
        pow(10,
            impedance /
            (
                276 /
                sqrt(k)
            )
        )
    );
#elif defined (__GNUC__)
    printf("%'.4f\n",
        r *
        powf(10,
            impedance /
            (
                276 /
                sqrtf(k)
            )
        )
    );
#endif
    return;
}

int main (int argc, char **argv)
{
    int opt;
    
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#endif

    while ((opt = getopt(argc, argv, "r:")) != -1) {
        switch (opt) {
            case 'r':
                if (argc == 5)
                {
                    reverseCalc(atof(argv[2]),
                        atof(argv[3]),
                        atof(argv[4]));
                    exit(EXIT_SUCCESS);
                }else {
                    usage();
                }
                break;
            default: /* '?' */
                usage();
            }
    }

    if (argc == 4)  // forward calculation
    {
        calculate(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    }else {
        usage();
    }

    return(EXIT_SUCCESS);
}
