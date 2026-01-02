/* Compile with gcc -Wall -o tankfreq tankfreq.c -lm
 *  The Lightning Stalker 2014
 */

#define PROGNAME "tankfreq"

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


int
main(int argc, char ** argv)
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
	printf("%'.3f\n",
		     1 / (
			 2 * M_PI * sqrt(
			     atof(argv[1]) * atof(argv[2]) * 1e-12
			     )
			 )
		     );
#else 
	gc = sprintf(buf, "%.3f\n",
		     1 / (
			 2 * M_PI * sqrt(
			     atof(argv[1]) * atof(argv[2]) * 1e-12
			     )
			 )
		     );

	gc = gc - 8;                      /* Digit grouping */
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
        puts ( \
            "\n"
            "  "PROGNAME" is an LC tank resonance frequency calculator.\n"
            "  output is frequency in Hz\n"
            "\n"
            "  Usage: "PROGNAME" [microfarads] [microhenries]\n"
            "\n"
            "  Example: $ "PROGNAME" 3.3 0.86207\n"
            "  Output should be: 94,360.861\n"
             );
        return (EXIT_FAILURE);
    }
    return (EXIT_FAILURE); /* makes tc happy */
}
