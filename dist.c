/* Compile with gcc -Wall -o dist dist.c -lm
 * Distance from A to B
 * Project Crew™ 9/24/2025
 * Thanks you (https://www.movable-type.co.uk/scripts/latlong.html)
 */

#define PROGNAME "dist"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define R        6371e3                 /* mean radius of Earth in meaters */
#if defined (__WATCOMC__)
#ifndef M_PI
#define M_PI     3.14159265358979323846 /* pi */
#endif
#endif

#if defined (__DOS__)
#define LESYM    "\xf3"
#define DEGSYM   "\xf8"
#else
#define LESYM    "≦"
#define DEGSYM   "°"                    /* differences of the codepage */
#endif


float
toRadians(float deg)
{
    return deg / (180.0 / M_PI);
}

/* get distance of remote */
/* haversine formula      */
float
getDistance
(
    float lata,
    float lona,
    float latb,
    float lonb
)
{
    float a,
          c,
          d,
          phi1,
          phi2,
          lambda1,
          lambda2,
          delphi,
          delambda;

    /* convert to radians */
    phi1    = toRadians(lata);
    lambda1 = toRadians(lona);
    phi2    = toRadians(latb);
    lambda2 = toRadians(lonb);

    /* so far away */
    delphi   = phi2    - phi1;
    delambda = lambda2 - lambda1;

    /* haversine formula */
#if defined (__WATCOMC__)
    a = sin(delphi / 2.0)   * sin(delphi / 2.0) +
        cos(phi1)           * cos(phi2)         *
        sin(delambda / 2.0) * sin(delambda / 2.0);

    c = 2.0 * atan2( sqrt(a), sqrt(1.0 - a) );

    /* we like the fp specific function available here */
#elif defined (__GNUC__)
    a = sinf(delphi / 2.0)   * sinf(delphi / 2.0) +
        cosf(phi1)           * cosf(phi2)         *
        sinf(delambda / 2.0) * sinf(delambda / 2.0);

    c = 2.0 * atan2f( sqrtf(a), sqrtf(1.0 - a) );
#endif

    d = R * c;     /* in meters */
    d = d * 1e-3;  /* in km     */

    return d;
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

        printf("%.3f\n", getDistance(lata, lona, latb, lonb));

        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" find the distance from geographic point A to point B\n"
              "  We use the haversine formula.  (Spherical model, so typical error "LESYM" 0.3%)\n"
              "\n"
              "  input WGS84 coordinates in signed decimal "DEGSYM"degrees, negative is west/south\n"
              "    alpha characters is ignore\n"
              "  output is distance in kilometers\n"
              "\n"
              "  Usage: "PROGNAME" [latitude A"DEGSYM"] [longitude A"DEGSYM"] [lat. B"DEGSYM"] [long. B"DEGSYM"]\n"
              "\n"
              "  Example:  $ "PROGNAME" 32.715 -117.1625  34.69 135.502  (San Diego, US - Osaka, JP)\n"
              "\n"
              "  Output should be: 9360.033 (km)\n"
              "\n", stderr);

        return (EXIT_FAILURE);
    }
}
/* from me */
