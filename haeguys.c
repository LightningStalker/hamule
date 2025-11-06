/* Compile with gcc -Wall -o haeguys haeguys.c -lm
 * 3 Guy Wires
 *  Project Crew 6/25/2025
 */

#define PROGNAME "haeguys"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI     3.14159265358979323846 /* pi */
#endif
#endif

int
main(int argc, char ** argv)
{
    if (argc == 3)
    {
        if (atof(argv[2]) < 90)
        {
#if defined (__WATCOMC__)
            double height              = atof(argv[1]),
                   /* convert to radians */
                   angle               = M_PI / (180 / atof(argv[2])),
                   /* law of sines */
                   guyl                = height / sin(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrt(pow(guyl, 2) - pow(height, 2)),
                   /* Lside */
                   side                = circumscribedCircle * sqrt(3);
#elif defined (__GNUC__)
            double height              = atof(argv[1]),
                   /* convert to radians */
                   angle               = M_PI / (180.0 / atof(argv[2])),
                   /* law of sines */
                   guyl                = height / sinf(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrtf(powf(guyl, 2.0) - powf(height, 2.0)),
                   /* Lside */
                   side                = circumscribedCircle * sqrtf(3);
#endif

            printf("%.3f  (length of each guy wire) total (x3) = %.3f\n", guyl, guyl * 3);
            printf("%.3f  (distance of guying stakes from center)\n",
                   circumscribedCircle);
            printf("%.3f  (distance between corners)\n", side);

            exit(EXIT_SUCCESS);
        }
    }else  /* print usage */
    {
        fputs("\n"
              "  "PROGNAME" is a guy wire setup calculator.\n"
              "  it is unit agnostic and meant for 3 guy wires\n"
              "\n"
              "  Usage:  $ "PROGNAME" [height of mast hold point] [desired angle in degrees]\n"
              "\n"
              "  Example: "PROGNAME" 16 45\n"
              "\n"
              "  Output should be: 22.627, 16.000, and 27.713\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif

        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);  /* some cc generate warning without it */
}
