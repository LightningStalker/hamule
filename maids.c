/* Compile with gcc -Wall -o maids maids.c maidenhead.c -lm
 * maidenhead library is require https://github.com/sp6q/maidenhead
 * Project Crew™ 9/5/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "maidenhead.h"

int
main(int argc, char ** argv)
{
    char * locator = 0;
    double lat, lon;

    switch (argc)
    {
        case 2:
            locator = argv[1];
            lat = mh2lat(locator);
            lon = mh2lon(locator);

            printf("%f, %f\n", lat, lon);

            return(EXIT_SUCCESS);
            break;

        case 3:
            lat = atof(argv[1]);
            lon = atof(argv[2]);
            locator = get_mh(lat, lon, 6);

            printf("%s\n", locator);

            return(EXIT_SUCCESS);
            break;

        default:
            puts("\n  maids is a maidenhead locator converter.");
            puts("  output is either maidenhead gridsquare or lat, long\n");

            puts("  Usage: maids [maidenhead locator]");
            puts("     or: maids [latitude] [longitude]\n");

            puts("  Example:  $ maids EF17");
            puts("  Output should be: -32.518924, -97.037847\n");

            puts("  Example:  $ maids -32.518 -97.037");
            puts("  Output should be: EF17LL\n");

            return(EXIT_FAILURE);
            break;
    }
}
