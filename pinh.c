/* Compile with gcc -Wall -o pinh pinh.c -lm
 *     The formulator of the pinhole camera
 *     microscopic probgramme by The Lightning Stalker ©April 11, 2022
 *     It's basically in case I can't remember the formula.'*/

#define PROGNAME "pinh"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char ** argv)
{
    if (argc == 3)
    {
        printf("%.3fmm\n",
               2e3 * sqrt(atof(argv[2]) * (atof(argv[1]) /
                                           1e9
                                           )
                          )
               );
        exit (EXIT_SUCCESS);
    }
    else if (argc == 4 && strcmp(argv[1], "-l") == 0)
    {
        printf("%.3fm\n",
               pow(atof(argv[3]) /
                   2e3, 2) /
               (atof(argv[2]) /
                1e9
               )
               );
        exit (EXIT_SUCCESS);
    }
    else // usage text
    {
        puts( \
            "\n"
            "  Pinhole camera aperture calculator\n"
            "  Output is pinhole diameter in millimeters\n"
            "  Option -l finds focal length of the pinholes\n"
            "\n"
            "  Usage: "PROGNAME" wavelength(nm) focal_length(m)\n"
            "     or: "PROGNAME" -l wavelength(nm) diameter(mm)\n"
            "\n"
            "  550nm is good rule of thumb for the visible spectrum.\n"
            "  Example: "PROGNAME" 413.000 0.95\n"
            "  Output should be: 1.253mm\n"
            "\n"
            "  If you discover a hole, -l will give its focal length in meters\n"
            "  Like so: "PROGNAME" -l 568.000 3.3705\n"
            "  Output should be: 5.000m"
            "\n"
            );
        exit (EXIT_FAILURE);
    }
    return(EXIT_FAILURE);
}
