/* compile with "gcc -Wall -oseriesw seriesw.c -lm"
 *
 * Steps through possible pot settings and finds the wattage dissipated
 * by the pot and a series resistor.
 * - by The Lightning Stalker 2014
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    float rres, pot, v, rpot, wres, wpot, wrpeak = 0, wppeak = 0;

    if (argc == 4)
    {
        rres = atof(argv[1]);
        pot = atof(argv[2]);
        v = atof(argv[3]);
        for (rpot = pot; rpot > -0.0001; rpot-=0.1)
        {
            wpot = pow (v / (rpot + rres), 2) * rpot;
            wres = pow (v / (rpot + rres), 2) * rres;
            if (wpot > wppeak) wppeak = wpot;
            if (wres > wrpeak) wrpeak = wres;
            printf("R2 = %1.4fΩ R1 = %1.4fW R2 = %1.4fW\n", rpot, wres, wpot);
        }
        puts("done.");
        printf("R1 peaked at %1.4fW, R2 peaked at %1.4fW\n", wrpeak, wppeak);
    }
    else
    {
        puts("seriesw finds wattages dissipated by a pot and series resistor.\n");
        puts("Usage: seriesw R1 R2 V");
        puts("R1 = Fixed Resistor Value");
        puts("R2 = Potentiometer Maximum Resistance");
        puts("V  = Appied Voltage");
        puts("Example: seriesw 4.7 50 1.25");
        puts("Output should end with: R1 peaked at 0.3324W, R2 peaked at 0.0831W");
        return(1);
    }

    return(0);
}
