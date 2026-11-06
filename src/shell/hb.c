/* Heading/Bearing between 2 points
 * Project Crew™ 9/20/2025
 * Thanks you (https://www.movable-type.co.uk/scripts/latlong.html)
 */

#define PROGNAME "hb"

#include <math.h>

#include "hb.h"
#include "define.h"
#include "func.h"

#include <stdio.h>
#include <stdlib.h>

/* get compass direction of initial bearing */
float
getDir
(
    float lata,
    float lona,
    float latb,
    float lonb
)
{
    float phi1,
          phi2,
          lambda1,
          lambda2,
          y,
          x,
          radians,
          bearing;

    /* convert to radians */
    phi1    = toRadians(lata);
    lambda1 = toRadians(lona);
    phi2    = toRadians(latb);
    lambda2 = toRadians(lonb);

    /* algorhythm */
#if defined (__WATCOMC__)
    y = sin(lambda2 - lambda1) * cos(phi2);
    x = cos(phi1) * sin(phi2) -
        sin(phi1) * cos(phi2) * cos(lambda2 - lambda1);
    radians = atan2(y, x);
    bearing = fmod(radians * 180.0 / M_PI + 360.0, 360.0);

    /* we like the fp specific function available here */
#elif defined (__GNUC__)
    y = sinf(lambda2 - lambda1) * cosf(phi2);
    x = cosf(phi1) * sinf(phi2) -
        sinf(phi1) * cosf(phi2) * cosf(lambda2 - lambda1);
    radians = atan2f(y, x);
    bearing = fmodf(radians * 180.0 / M_PI + 360.0, 360.0);
#endif

    return bearing;
}


int
hb(int argc, char ** argv)
{
    if (argc == 5)
    {
        float lona,
              lata,
              lonb,
              latb;

        lata = atof(argv[1]);
        lona = atof(argv[2]);
        latb = atof(argv[3]);
        lonb = atof(argv[4]);

        printf("%.4f\n", getDir(lata, lona, latb, lonb));

        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" find the initial bearing from point A to point B\n"
              "  It help points the antenna.\n"
              "\n"
              "  input WGS84 coordinates in signed decimal "DEGSYM"degrees, negative is west/south\n"
              "    alpha characters is ignore\n"
              "  output is compass bearing in degrees from true north\n"
              "  standing on point A \"looking\" at point B\n"
              "\n"
              "  Usage: "PROGNAME" [latitude A"DEGSYM"] [longitude A"DEGSYM"] [lat. B"DEGSYM"] [long. B"DEGSYM"]\n"
              "\n"
              "  Example:  # "PROGNAME" 32.715 -117.1625  34.69 135.502  (San Diego, USA - Osaka, JP)\n"
              "\n"
              "  Output should be: 307.9111 (degrees "DEGSYM")\n"
              "\n",
              stderr);
        return (EXIT_FAILURE);
    }
}

#undef  PROGNAME
