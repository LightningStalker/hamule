/* Compile with gcc -Wall -o haeguys haeguys.c -lm
 *  The Lightning Stalker 6/25/2025
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
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
                   angle               = M_PI / (180 / atof(argv[2])),
                   /* law of sines */
                   guyl                = height / sin(angle),
                   /* pythagorean theorem */
                   circumscribedCircle = sqrt(pow(guyl, 2) - pow(height, 2));

            printf("length of each guy wire: %'.3f\n", guyl);
            printf("distance of guying stakes from center: %'.3f\n",
                circumscribedCircle);
            printf("distance between corners: %'.3f\n", circumscribedCircle * sqrt(3));
            exit(EXIT_SUCCESS);
        }
    }
    
    else  /* print usage */
    {
	puts("haeguys is a guy wire setup calculator.");
	puts("it is unit agnostic and meant for 3 guy wires\n");
	puts("Usage: haeguys [mast height] [desired angle in degrees]");
	puts("Example: haeguys 16 45");
	puts("Output should be: 22.627, 16.000, and 27.713");
        exit(EXIT_FAILURE);
    }
}
