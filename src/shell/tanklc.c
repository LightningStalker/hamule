/*    The Lightning Stalker ~2015 */

#define PROGNAME    "tanklc"

#include "tanklc.h"
#include "define.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int tanklc (int argc, char **argv)
{
    if (argc == 3)
    {
        printf ("%'.9f\n",
                           25e10 /
                           (
                            powf(M_PI, 2.0) * atof(argv[2]) *
                            powf(atof(argv[1]), 2.0)
                           )
               );

	return(EXIT_SUCCESS);
    }else
    {
        fputs("\n"
              "  "PROGNAME" finds a value of L or C given resonance frequency (fres) and either\n"
              "    L or C.  If you enter the inductance (L), you get the capacitance (C),\n"
              "    if you enter the capacitance, you get the inductance.\n"
              "\n"
              "  For fres in the Hz,  L/C values are the microhenries and microfarads.\n"
              "  For fres in the kHz,        ...         microhenries and picofarads.\n"
              "\n"
              "  Usage: "PROGNAME" fres(Hz, kHz) {L || C}( "MUSYM"H || "MUSYM"F, "MUSYM"H || pF )\n"
              "  Example: We want the resonance frequency of kHz,\n"
              "    so for 300.0kHz and a 38"MUSYM"H inductor, the command line will be:\n"
              "     $ "PROGNAME" 300.000 38\n"
              "    And the output should be:\n"
              "    7406.51... (pF), giving the value for his capacitor.\n"
              "  We can then do \' $ "PROGNAME" 300 7406.519\' and get back the first one\n"
              "    inductor value of 38 ("MUSYM"H)  (Actual get \'37.999998842\' (it might vary a\n"
              "    little on the different platforms)  He is very close!)\n",
              stderr);
        putc('\n', stderr);
        return(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

#undef  PROGNAME
