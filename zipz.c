/* Compile with gcc -Wall -o zipz zipz.c -lm
    The Lightning Stalker 2024 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

void
usage(void) {
    puts ("zipz calculates the impedance of ladder line and zip cord");
    puts ("and reverse calculation of conductor spacing");
    puts ("output is impedance in Ohms\n");
    puts ("Usage: zipz distance radius k");
    puts ("   or: zipz -r impedance, radius, k");
    puts ("Distance is distance between centers of conductors");
    puts ("Radius is radius of one conductor");
    puts ("k is relative permittivity in region between conductors\n");
    puts ("Example 1: zipz 1.2 3.25 0.05");
    puts ("Output should be: 456.8(Ω)\n");
    puts ("Example 2: zipz -r 456.8 0.05 1.2");
    puts ("Output should be: 3.2510 (distance d)\n");
    exit (EXIT_FAILURE);
}

void
calculate(float k, float d, float r) {
    printf ("%'.1f\n",
        276.0 /
        sqrtf(k) *
        log10f(d / r)
        );
    return;
}

void
reverseCalc(float impedance, float r, float k) {
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
    return;
}

int main (int argc, char **argv)
{
    int opt;
    
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping

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
                puts("default");
                usage();
            }
    }

    if (argc == 4)  // forward calculation
    {
        calculate(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    }else {
        usage();
    }

    exit(EXIT_SUCCESS);
}
