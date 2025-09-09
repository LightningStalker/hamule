/* Compile with gcc -Wall -o moxon moxon.c -lm
 * Moxon rectangle
 * https://www.moxonantennaproject.net/design.htm
 * Project Crew™ 9/8/2025
 */

#define PROGNAME "moxon"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* speed of light */
#define M_C       299.792458

/* constants of polynomial */
/* A */
#define AA       -0.0008571428571
#define AB       -0.009571428571
#define AC        0.3398571429
/* B */
#define BA       -0.002142857143
#define BB       -0.02035714286
#define BC        0.008285714286
/* C */
#define CA        0.001809523381
#define CB        0.01780952381
#define CC        0.05164285714
/* D */
#define DA        0.001
#define DB        0.07178571429


int
main(int argc, char ** argv)
{
    unsetenv("LC_ALL");
    setlocale(LC_NUMERIC, "");  /* This should give us digit grouping */

    double f,   /* design frequency    */
           wd,  /* wire diameter       */
           dw,  /* ... in wavelengths  */
           d1,  /* log10 of ...        */
           wl,  /* wavelength          */
           a,   /* dimensions of xymox */
           b,   /* ... in wl           */
           c,   /* ...                 */
           d,   /* ...                 */
           e,   /* ...                 */
           ac,  /* ... in cm           */
           bc,  /* ...                 */
           cc,  /* ...                 */
           dc,  /* ...                 */
           ec;  /* ...                 */


    if (argc == 3)
    {
        f  = atof(argv[1]);
        wd = atof(argv[2]);

        wl = M_C / f;
        dw = wd / (wl * 1000.0);
        d1 = log10f(dw);

        /* malt-o-polyno-meal */
        a = (AA * (powf(d1, 2.0))) + (AB * d1) + AC;
        b = (BA * (powf(d1, 2.0))) + (BB * d1) + BC;
        c = (CA * (powf(d1, 2.0))) + (CB * d1) + CC;
        d = (DA * d1) + DB;
        e = (b + c) + d;

        wl = wl * 1e2;   /* convert to cm */
        ac = a * wl;
        bc = b * wl;
        cc = c * wl;
        dc = d * wl;
        ec = e * wl;
        wl = wl * 1e-2;  /* wavelength pop */


        /* time to print the hard work */
        printf("\n"
               "  working freq: %'10.3fMHz    wire diameter:            %4.1fmm\n"
               "    wavelength:  %8.2fm       wire diam. in wavelengths: %.6f\n"
               "  ___________________________________________________________________\n"
               "  in wavelengths    in centimeters\n"
               "  A = %.5f        %'8.2fcm\n"
               "  B = %.5f        %8.2fcm\n"
               "  C = %.5f        %8.2fcm\n"
               "  D = %.5f        %8.2fcm\n"
               "  E = %.5f        %'8.2fcm\n"
               "\n", f, wd, wl, dw, a, ac, b, bc, c, cc, d, dc, e, ec);

        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" is a Moxon antenna calculator.\n"
              "  It give the dimension for elements of the antenna in cm.\n"
              "\n"
              "  Usage: "PROGNAME" [f.MHz] [elements diameter]\n"
              "\n"
              "  Example:  $ "PROGNAME" 146 5\n"
              "\n"
              "  Output should be:\n"
              "  A = 0.35902\n"
              "  B = 0.04685\n"
              "  C = 0.01746\n"
              "  D = 0.06917\n"
              "  E = 0.13348\n"
              "\n"
              "  (https://www.moxonantennaproject.net/design.htm)\n"
              "\n", stderr);

        return (EXIT_FAILURE);
    }
}
