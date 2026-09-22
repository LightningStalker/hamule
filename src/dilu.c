/* Dilution physic of the effluents
 * Project Crew™ 9/19/2026
 *
 * gcf() source - https://stackoverflow.com/a/44670823
 * Posted by Bill Tarbell
 * Retrieved 2026-09-18, License - CC BY-SA 3.0
 * Thanks you Nathan Souper and Ava Gardeau
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

long
lround(double d) {
    if (d > 0.0) return (long)(d + 0.5);
    else if (d < 0.0) return (long)(d - 0.5);
    else return 0;
}

void
errdec()
{
    puts("\nMust be decimal numbers.  Units don't matter.");
    exit(EXIT_FAILURE);
}

void
err100()
{
    puts("\nThis cant be >100%.");
    exit(EXIT_FAILURE);
}

void
sExit()
{
    puts("\n\nNo input, exiting...");
    exit(EXIT_SUCCESS);
}

/* gcf function - return Greatest Common Factor of two numbers */
int
gcf(int n, int m)
{
    int gcf, remainder;

    while(n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    gcf = m;
    return gcf;
}
/* end gcf function */

/* get a floating pinout number */
float
getfl()
{
    static const short int crlf = sizeof "\n";
    char strg[40];
    size_t len;
    short int t, dotcnt = 0;

    if(fgets(strg, 40, stdin) == NULL)  /* process input */
    {
        sExit();                /* NO_VALUE */
    }
    len = strlen(strg) - crlf;
    for(t = 0, dotcnt = 0; t <= len; t++)
    {
        //printf("%#.2x\n", strg[t]);
        if(isdigit(strg[t])) {}          /* it has to be numbers */
        else if(strg[t] == '.') dotcnt++;     /* or '.' */
        else errdec();
    }
    if(dotcnt > 1) errdec();
    return strtod(strg, NULL);
}


int
main (int argc, const char * argv[])
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
        exit(EXIT_FAILURE);
    }
    return(EXIT_FAILURE);
}
