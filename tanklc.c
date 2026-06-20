/* Compile with gcc -Wall -o tanklc tanklc.c -lm
    The Lightning Stalker ~2015 */

#define PROGNAME    "tanklc"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined (__GNUC__)
#include <locale.h>
#else
#include <string.h>
#endif

#if defined (__VBCC__) || defined (__WATCOMC__)
#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi */
#endif
const char dgchar = ',';            /* digit grouping character */
#endif
#if defined (__DOS__)
#define MUSYM       "\x00e6"
#else
#define MUSYM       "\u00b5"
#endif

int main (int argc, char **argv)
{
#if defined (__GNUC__)
    unsetenv ("LC_ALL");
    setlocale (LC_NUMERIC, "");  // This should give us digit grouping
#else
    char buf[40];                   /* result buffer */
    char output[40];                /* output buffer */
    int c = 0,                      /* output string char count */
	lc = 0,                     /* result buffer char count */
	gc;                         /* Number of chars for grouping */
#endif

    if (argc == 3)
    {
#if defined (__GNUC__)
        printf ("%'.9f\n",
            pow(1 /
            atof(argv[1]) / (2 * M_PI), 2) /
            atof(argv[2]) * 1e6
            );
#else
        gc = sprintf (buf, "%.9f\n",
            pow(1 /
            atof(argv[1]) / (2 * M_PI), 2) /
            atof(argv[2]) * 1e6
            );

        gc = gc - 14;                  /* Digit grouping */
        if (gc > 0)
        {
            do
            {
            gc--;
            if (gc % 3)
                output[c] = buf[lc];  /* Normal digit */
            else
            {
                output[c] = buf[lc];  /* Digit with  */
                c++;
                output[c] = dgchar;   /* grouping char */
            }
            c++;
            lc++;
            }
            while (gc);
        }

	strncpy(&output[c], &buf[lc], 40); /* Copy what remains */
	printf("%s", output);
#endif
	exit(EXIT_SUCCESS);
    }else
    {
        puts ("\n"
              "  "PROGNAME" finds a value of L or C given resonance frequency (fres) and either\n"
              "    L or C.  If you enter the inductance (L), you get the capacitance (C),\n"
              "    if you enter the capacitance, you get the inductance.\n"
              "\n"
              "  For fres in the Hz,  L/C values are the millihenries and microfarads.\n"
              "  For fres in the kHz,        ...         microhenries and microfarads.\n"
              "  For fres in the MHz,        ...         microhenries and picofarads.\n"
              "\n"
              "  Usage: "PROGNAME" fres(Hz, kHz, MHz) {L || C}( mH || "MUSYM"F, "MUSYM"H || "MUSYM"F, "MUSYM"H || pF )\n"
              "  Example: We have a fres in the kHz,\n"
              "    so for 300.0kHz and a 38"MUSYM"H inductor, the command line will be:\n"
              "     $ "PROGNAME" 300.000 38\n"
              "    And the output should be:\n"
              "    0.007406519 ("MUSYM"F), giving the value for his capacitor.\n"
              "  We can then do \' $ "PROGNAME" 300.0 0.007406519\' and get back the first one\n"
              "    inductor value of 38 ("MUSYM"H)  (Actual get \'38.000001396\'.  He is very close!)\n"
             );
        exit(EXIT_FAILURE);
    }
}
