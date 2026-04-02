/*  Compile with $ gcc -Wall -o bucks bucks.c
 * For Watcom: $ wcl -bcl=$(DEST_OS) -wx -fe=$(EXE_file) bucks.c
 * or use make
 * Buck converter Power State calculator
 * Formuli from SLVA477B by TI, Rev. 8/2015
 * C adaptation by Project Crew 11/5/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void
usage()
{
    puts("\n   bucks is a buck converter power state calculator.\n"
           "   5 output paramaters including inductor value\n"
           "\n"
           "   5 position dependent input paramaters from stdin, 1 per line\n"
           "   scriptable and designed to be used with formvar\n"
           "   Input: frequency, Vin, Vout, Ioutmax, Voutripple\n"
#if defined (__DOS__)
           "   Output: dutyCycle, Iripple, L(\xe6\H), "
           "minimumOutputCapacitance(\xe6\F), Idiode");
#else
           "   Output: dutyCycle, Iripple, L(\u00b5H), "
           "minimumOutputCapacitance(\u00b5F), Idiode\n");
#endif

    exit(EXIT_FAILURE);
}


int
main(int argc, char ** argv)
{
    char strg[40];
    double
        freq,                 // frequency
        vin        = 0,       // input voltage
        vout       = 0,       // output voltage
        ioutmax    = 0,       // max output current
        voutripple = 0,       // desired output voltage ripple
        D,                    // duty cycle
        iripple,              // ripple current
        L,                    // inductor value
        mincap,               // minimum output capacitance
        idiode;               // avg. forward diode current

    if(argc == 1)
    {
        fputs(" operating frequency(Hz)? ", stderr);
#if defined (__DOS__)
        delay(10);
#else
        usleep(1e4);
#endif
        if(fgets(strg, 40, stdin) == NULL) // process input
            usage();     // NO_VALUE
        else if ((isdigit(strg[0]) == 0) && (strg[0] != '.'))
            usage();
        freq           = atof(strg);
        fputs("           input voltage? ", stderr);
#if defined (__DOS__)
        delay(10);
#else
        usleep(1e4);
#endif
        if(fgets(strg, 40, stdin))
            vin        = atof(strg);
        fputs("          output voltage? ", stderr);
        if(fgets(strg, 40, stdin))
            vout       = atof(strg);
        fputs("      max output current? ", stderr);
        if(fgets(strg, 40, stdin))
            ioutmax    = atof(strg);
        fputs("   output voltage ripple? ", stderr);
        if(fgets(strg, 40, stdin))
            voutripple = atof(strg);

        // begin calc section
        D = vout * 0.85 / vin;  // equation 1
        iripple = 0.3 * ioutmax;  // equation 6
        L = vout * (vin - vout) / (iripple * freq * vin);  // equation 5
        mincap = iripple / (8.0 * freq * voutripple);  // equation 12
        idiode = ioutmax * (1 - D);  // equation 7

        // spacer
        fputs("-\n     Result:\n", stderr);

        // send formatted output
        fputs(" output duty cycle:           ", stderr);
        printf("%.1f", D * 100);
        fflush(stdout);
        fputs(" %", stderr);
        puts("");
        fflush(stdout);
        fputs(" ripple current:              ", stderr);
        printf("%.3f", iripple);
        fflush(stdout);
        fputs(" A", stderr);
        puts("");
        fflush(stdout);
        fputs(" inductor:                    ", stderr);
        printf("%.0f", L * 1e6);
        fflush(stdout);
#if defined (__DOS__)
        fputs(" \xe6\H", stderr);
#else
        fputs(" \u00b5H", stderr);
#endif
        puts("");
        fflush(stdout);
        fputs(" minimum output capacitance:  ", stderr);
        printf("%.0f", mincap * 1e6);
        fflush(stdout);
#if defined (__DOS__)
        fputs(" \xe6\F", stderr);
#else
        fputs(" \u00b5F", stderr);
#endif
        puts("");
        fflush(stdout);
        fputs(" current through diode:       ", stderr);
        printf("%.3f", idiode);
        fflush(stdout);
        fputs(" A\n", stderr);
        puts("");
        exit(EXIT_SUCCESS);
    }else
    {
        usage();
    }
    return(EXIT_SUCCESS);
} /* main */
