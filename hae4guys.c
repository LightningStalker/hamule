/* Compile with gcc -Wall -o hae4guys hae4guys.c -lm
 * 4 Guy Wires
 *  Project Crew 9/22/2025
 */

#define PROGNAME "hae4guys"

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
            double height              = atof(argv[1]),
                   /* convert to radians */
                   angle               = M_PI / (180.0 / atof(argv[2])),
                   /* law of sines */
                   guyl                = height / sinf(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrtf(powf(guyl, 2.0) - powf(height, 2.0)),
                   /* ... again */
                   side                = sqrtf(powf(circumscribedCircle * 2.0, 2.0) / 2.0);

            printf("%.3f  (length of each guy wire) total (x4) = %.3f\n", guyl, guyl * 4);
            printf("%.3f  (distance of guying stakes from center)\n",
                   circumscribedCircle);
            printf("%.3f  (distance between corners)\n", side);

            exit(EXIT_SUCCESS);
        }
    }else  /* print usage */
    {
        fputs("\n"
              "  "PROGNAME" is a guy wire setup calculator.\n"
              "  it is unit agnostic and meant for 4 guy wires\n"
              "\n"
              "  Usage:  $ "PROGNAME" [height of mast hold point] [desired angle in degrees]\n"
              "\n"
              "  Example: "PROGNAME" 16 42\n"
              "\n"
              "  Output should be: 23.912, 17.770, and 25.130\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif

        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);  /* some cc generate warning without it */
}
