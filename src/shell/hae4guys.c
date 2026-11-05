/* 4 Guy Wires
 *  Project Crew 9/22/2025
 */

#define PROGNAME "hae4guys"

#include <math.h>

#include "hae4guys.h"
#include "define.h"

#include <stdio.h>
#include <stdlib.h>


int
hae4guys(int argc, char ** argv)
{
    if (argc == 3)
    {
        if (atof(argv[2]) < 90)
        {
#if defined (__WATCOMC__)
            double height              = atof(argv[1]),
                   /* convert to radians */
                   angle               = M_PI * atof(argv[2]) / 180.0,
                   /* law of sines */
                   guyl                = height / sin(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrt(pow(guyl, 2) - pow(height, 2)),
                   /* ... again */
                   side                = sqrt(2) * circumscribedCircle;
#elif defined (__GNUC__)
            double height              = atof(argv[1]),
                   /* convert to radians */
                   angle               = M_PI * atof(argv[2]) / 180.0,
                   /* law of sines */
                   guyl                = height / sinf(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrtf(powf(guyl, 2.0) - powf(height, 2.0)),
                   /* ... again */
                   side                = M_SQRT2 * circumscribedCircle;
#endif

            printf("%.3f  (length of each guy wire) total (x4) = %.3f\n", guyl, guyl * 4);
            printf("%.3f  (distance of guying stakes from center)\n",
                   circumscribedCircle);
            printf("%.3f  (distance between corners)\n", side);

            return(EXIT_SUCCESS);
        }
    }else  /* print usage */
    {
        fputs("\n"
              "  "PROGNAME" is a guy wire setup calculator.\n"
              "  it is unit agnostic and meant for 4 guy wires\n"
              "\n"
              "  Usage: "PROGNAME" [height of mast hold point] [desired angle in degrees]\n"
              "\n"
              "  Example:  $ "PROGNAME" 16 42\n"
              "\n"
              "  Output should be: 23.912, 17.770, and 25.130\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
        return(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);  /* some cc generate warning without it */
}

#undef  PROGNAME
