/* Compile with gcc -Wall -o hb hb.c -lm
 * Heading/Bearing between 2 points
 * Project Crew™ 9/20/2025
 * Thanks you (https://www.movable-type.co.uk/scripts/latlong.html)
 */

#define PROGNAME "hb"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


float
toRadians(float deg)
{
    return deg / (180.0 / M_PI);
}

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
    float y,
          x,
          radians,
          bearing;

    /* convert to radians */
    lata = toRadians(lata);
    lona = toRadians(lona);
    latb = toRadians(latb);
    lonb = toRadians(lonb);

    /* algorhythm */
    y = sinf(lonb - lona) * cosf(latb);
    x = cosf(lata) * sinf(latb) -
        sinf(lata) * cosf(latb) * cosf(lonb - lona);
    radians = atan2f(y, x);
    bearing = fmodf(radians * 180.0 / M_PI + 360.0, 360.0);

    return bearing;
}


int
main(int argc, char ** argv)
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

        printf("%.2f\n", getDir(lata, lona, latb, lonb));

        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" find the initial bearing from point A to point B\n"
              "  It help points the antenna.\n"
              "\n"
              "  output is compass bearing in degrees from true north\n"
              "  standing on point A \"looking\" at point B\n"
              "\n"
              "  Usage: "PROGNAME" [latitude A°] [longitude A°] [lat. B°] [long. B°]\n"
              "\n"
              "  Example:  $ "PROGNAME" 33 44.366111  34.69 135.502  (Baghdad, IQ - Osaka, JP)\n"
              "\n"
              "  Output should be: 59.40 (degrees °)\n"
              "\n", stderr);

        return (EXIT_FAILURE);
    }
}
