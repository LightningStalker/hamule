/* Compile with gcc -Wall -o boost boost.c
 * Online version:
 *  https://learn.adafruit.com/diy-boost-calc/the-calculator
 * Consult SLVA372 from TI
 * C port by Project Crew 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined (__GNUC__)
#define MAX(x, y) ( \
        { __auto_type __x = (x); __auto_type __y = (y); \
          __x > __y ? __x : __y; })
#endif

int
main(int argc, char ** argv){

    char strg[40];
    double
        freq,           // frequency
        vinmin,         // minimum input voltage
        vinmax,         // max ..
        voutmin,        // minimum output voltage
        voutmax,        // max ..
        iout,           // output current
        vripple,        // ripple voltage
        L, L2, L3, L4,  // inductor val and intermediates
        D1, D2, D3, D4, // duty cycle intermediates
        Ipk, Ipk2, Ipk3, Ipk4, // peak current
        cap;            // capacitance filter
    int minduty,        // minimum duty cycle
        maxduty;        // maximum ..

    if (argc == 1) {
        fgets(strg, 40, stdin); // process input
        freq = atof(strg);
        fgets(strg, 40, stdin);
        vinmin = atof(strg);
        fgets(strg, 40, stdin);
        vinmax = atof(strg);
        fgets(strg, 40, stdin);
        voutmin = atof(strg);
        fgets(strg, 40, stdin);
        voutmax = atof(strg);
        fgets(strg, 40, stdin);
        iout = atof(strg);
        fgets(strg, 40, stdin);
        vripple = atof(strg);

        // begin calc section
        minduty = 100 * (1 - vinmax / voutmin);
        maxduty = 100 * (1 - vinmin / voutmax);

        // calculate for vinmin and voutmin
        D1 = (1 - vinmin / voutmin);
        L = D1 * vinmin * (1 - D1) / (freq * 2 * iout);
        // .. vinmin and voutmax
        D2 = (1 - vinmin / voutmax);
        L2 = D2 * vinmin * (1 - D2) / (freq * 2 * iout);
        // .. vinmax and voutmin
        D3 = (1.0 - vinmax / voutmin);
        L3 = D3 * vinmax * (1 - D3) / (freq * 2 * iout);
        // .. vinmax and voutmax
        D4 = (1.0 - vinmax / voutmax);
        L4 = D4 * vinmax * (1.0 - D4) / (freq * 2.0 * iout);

        L = MAX(L, L2); // > out of 4
        L = MAX(L, L3);
        L = MAX(L, L4);

        Ipk = vinmin * D1 / (freq * L);
        // for vinmin and voutmax
        Ipk2 = vinmin * D2 / (freq * L);
        // for vinmax and voutmin
        Ipk3 = vinmax * D3 / (freq * L);
        // for vinmax and coutmax
        Ipk4 = vinmax * D4 / (freq * L);

        Ipk = MAX(Ipk, Ipk2);
        Ipk = MAX(Ipk, Ipk3);
        Ipk = MAX(Ipk, Ipk4);

        // Find the minimum capacitor Cap &gt; Iout / (Vripple * freq)
        cap = iout / (vripple * freq);
        cap = cap * 1e6;

        L = L * 1e6;


        printf("%'d\n%'d\n%'.3f\n%'.3f\n%'.3f\n%'.3f\n",
               minduty,
               maxduty,
               L,
               Ipk,
               cap,
               voutmax
               );
        exit(EXIT_SUCCESS);
    } else {
        puts("boost is a boost converter calculator.");
        puts("6 output paramaters including inductor value\n");
        puts("7 position dependent input paramaters from stdin, 1 per line");
        puts("scriptable and designed to be used with formvar");
        puts("Input: frequency, Vinmin, Vinmax, Voutmin, Voutmax, Iout, Vripple");
        puts("Output: minduty, maxduty, L(µH), Ipeak, capacitance(µF), Voutmax");
        exit(EXIT_FAILURE);
    }
} /* main */
