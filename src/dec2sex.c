/* Compile with gcc -o dec2sex dec2sex.c -lm */

#define PROGNAME    "dec2sex"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined (__DOS__)
#define DEGSYM   "\xf8"

double round(double d) {
    if (d > 0.0) return floor(d + 0.5);
    else if (d < 0.0) return ceil(d - 0.5);
    else return d;
}

long lround(double d) {
    if (d > 0.0) return (long)(d + 0.5);
    else if (d < 0.0) return (long)(d - 0.5);
    else return 0;
}
#else
#define DEGSYM   "\u00b0"               /* differences of the codepage */
#endif


int main (int argc, char **argv)
{
    int d, m, s, ms;
    double mm, ss;

/* in any case */
    if (argc > 1)
    {
        d  = floor(atof(argv[1]));
    }

    switch (argc)
    {
        case 2:
/* decimal pure */
            m  = floor(mm = (atof(argv[1]) - d) * 60.0);
            break;
        case 3:
/* decimal minutes */
            m  = floor(mm = atof(argv[2]));
            break;
        default:
/* usage */
            fputs("\n"
                  "  "PROGNAME" is a decimal to sexagesimal (base 60) converter.\n"
                  "  "PROGNAME" converts decimal degree coordinates into sexagesimal deg/m/s/mils\n"
                  "  use ABSOLUTE VALUE of any negative number, and garbage in = garbage out\n"
                  "  output is the coordinates in base 60\n"
                  "  "PROGNAME" is not sexy.\n"
                  "\n"
                  "  Usage: "PROGNAME" XX.XXXXXX     (where X is some number)\n"
                  "     Or: "PROGNAME" XX XX.XXXXXX  (for decimal minutes)\n"
                  "  Example: "PROGNAME" 43.923056\n"
                  "  Output should be: 43"DEGSYM"55\'23\"2ms\n"
                  "                    43"DEGSYM"55.383360\'\n"
                  "\n", stderr);
#if defined (__GNUC__)
            putc('\n', stderr);
#endif
            return (EXIT_FAILURE);
            break;
    }
/* seconds and milli */
    s  = floor(ss = (mm - m) * 60.0);
    ms = round((ss - s) * 1000.0); // last one get rounded instead

/* output */
    printf ("%i"DEGSYM"%i\'%i\"%ims\n", d, m, s, ms);
    if (argc != 3)
    {
/* we aready has it */
        printf ("%i"DEGSYM"%f\'\n", d, mm);
    }
    return (EXIT_SUCCESS);
}
