/* Compile with gcc -Wall -o lpda lpda.c -lm
 * Log-Periodic antenna
 * Project Crew™ 9/7/2025
 */

#define PROGNAME "lpda"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* speed of light */
#define M_C      299792458

int
main(int argc, char ** argv)
{
    unsetenv("LC_ALL");
    setlocale(LC_NUMERIC, "");  /* This should give us digit grouping */

    int n, t;           /* number elements */

    float tau,          /* scaling factor      */
          fl,           /* low frequency       */
          fh,           /* high frequency      */
          boom_length,  /* length of the boom  */
          ln,           /* element length      */
          ratio,        /* freq ratio          */
          xn;           /* spacings            */

    char spc[] = "   ";

    if (argc == 4)
    {
        fl = atof(argv[1]);
        fh = atof(argv[2]);
        n  = atoi(argv[3]);

        if (n > 30)
        {
            fputs("\n  too many elements (Why you need so many?)\n\n", stderr);
            return(EXIT_FAILURE);
        }else if (n < 3)
        {
            fputs("\n  elements no enough\n\n", stderr);
            return(EXIT_FAILURE);
        }

        /* find scaling factor */
        tau = powf( 10, log10f(fl / fh) / (n - 1) );

        /* boom length */
        boom_length = M_C / (fl * 1e4);

        /* longest element */
        ln = boom_length / 4;

        /* ratio of frequency */
        ratio = fh / fl;

        /* space the element */
        xn = ratio * boom_length * (1 - tau);

        /* time to print the hard work */
        printf("\n"
               "  scaling factor τ = %.6f\n"
               "  boom length      = %'.1fcm\n"
               "\n", tau, boom_length);

        puts("      length   spacing\n"
             "  ______________________");
        printf("  LL%s%.1f     0\n", spc, ln);
        ln = ln * tau;

        for (t = 2; t <= n; t++)
        {
            printf("  L%i%s%.1f     %.1f\n", t, spc, ln, xn);
            ln = ln * tau;
            xn = xn * tau;
            if (t == 9)
                spc[2] = 0;  /* short the string to line up */
        }
        puts("");
        return (EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" is a log-periodic antenna calculator.\n"
              "  It give the dimension for elements of the antenna in cm.\n"
              "\n"
              "  Usage: "PROGNAME" [fLow] [fHigh] [NumElements]\n"
              "\n"
              "  Example:  $ "PROGNAME" 150 300 5\n"
              "\n"
              "  Output should be:\n"
              "  LL   50.0     0\n"
              "  L2   42.0     63.6\n"
              "  L3   35.3     53.5\n"
              "  L4   29.7     45.0\n"
              "  L5   25.0     37.8\n"
              "\n"
              "  (https://en.wikipedia.org/wiki/Log-periodic_antenna)\n"
              "\n", stderr);

        return (EXIT_FAILURE);
    }
}
