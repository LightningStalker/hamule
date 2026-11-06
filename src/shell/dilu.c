/* Dilution physic of the effluents
 * Project Crew™ 9/19/2026
 *
 * Thanks you Nathan Souper and Ava Gardeau
 */

#include "dilu.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void
err100()
{
    puts("\nThis cant be >100%.");
    return;
}


int
dilu (int argc, char * argv[])
{
    /* insert code here... */
    /*--declarations */
    float cInit,
          vDis,
          cTarg,
          cFac,
          vAdd,
          vTot,
          vDil,
          vSup;
    int   ngcf,
          num1,
          den1,
          num2,
          den2;

    /*--get user input */
    printf("Initial %% concentration........: ");
    cInit = getfl();
    if(cInit > 100) err100();
    printf("Start volume or volume to fill.: ");
    vDis  = getfl();
    printf("Target  %% concentration........: ");
    cTarg = getfl();
    if(cTarg > 100) err100();

    /* "Math" */
    if(cInit >= cTarg)
    {
        cFac = cInit / cTarg;
        vTot = vDis * cFac;
        vAdd = vTot - vDis;
        vSup = cTarg * vDis / cInit;
        vDil = vDis - vSup;
#if defined (__WATCOMC__)
        num1 = lround(cTarg * 100.0);
#else
        num1 = round(cTarg * 100.0);
#endif
        den1 = 1e4 - num1;
        ngcf = gcf(num1, den1);
        num2 = num1 / ngcf;
        den2 = den1 / ngcf;
        printf("\nTarget dilution ratio: %i:%i\n", num2, den2);
        printf("Add %.2f diluent to %.2f units of %.2f%%\n"
               "  to get %.2f dilute of %.2f%%\n",
               vAdd, vDis, cInit, vTot, cTarg);
        printf("Or add %.2f of %.2f%% solution and %.2f diluent\n"
               "  to get the %.2f units at %.2f%% concentration\n",
               vSup, cInit, vDil, vDis, cTarg);
    }else
    {
        puts("Initial concentration is lower than you target. I can't dilute.");
        return(EXIT_FAILURE);
    }
    return(EXIT_FAILURE);
}
