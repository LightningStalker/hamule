/* Compile with gcc -o nib nib.c -lm
 * convert numbers to IEC 60027-2 A.2 format
 *  Project Crew™ 1/1/2026
 */

#define PROGNAME "nib"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int
main(int argc, char ** argv)
{
    if (argc > 1)
    {
        int t = 0;
        long double n;
        char unit[] = "hKMGTPEZYRQ";

        if(((n = atof(argv[1])) < LDBL_MAX) && n >= 0)
        {
            while(floor(n) >= 1024)
            {
                n /= 0x400L;
                t++;
            }
    
            if(t && t < 11)
            {
                printf("%.2Lf%c\n", n, unit[t]);
            }else if(t < 11)
            {
                printf("%.0Lf\n", n);
            }else
            {
                printf("%.2Lf * 1024^%i\n", n, t);
            }
        }else
        {
            puts("nib: ERROR: input out of range");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }else  /* print usage */
    {
        fputs("\n"
              "  "PROGNAME" will convert the number to IEC 60027-2 A.2 format.\n"
              "    (power of 2 and result < 1000)\n"
              "    If the input is number is bytes, \"iB\" can be add to the end,\n"
              "    for \"KiB\" (kibibytes), \"MiB\" (mebibytes), etc.\n"
              "\n"
              "  note: Very large numbers will convert to the exponential notation.\n"
              "\n"
              "  Usage:  $ "PROGNAME" [some number]\n"
              "\n"
              "  Example: "PROGNAME" 11477\n"
              "\n"
              "  Output should be: 11.21Ki\n",
              stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif

        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);  /* some cc generate warning without it */
}