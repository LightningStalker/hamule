/* Simplify some fractions
 * Project Crew™ 9/18/2026
 */

#include "simp.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void
simp_usage()
{
    puts("\nYou can't do that!  It's gotta be 2 positive integers "
         "separated by a forward\n"
         "slash.");
    return;
}

void
theGoodEnding()
{
    puts("\n\nNo input, exiting...");
    return;
}


int
simp (int argc, char * argv[])
{
    /* insert code here... */
    /*--declarations */
    int num, den;
    int newNum = 0, newDen = 0;
    int ngcf;
    short int rv = 0, t, slashcnt = 0;
    char strg[40];
    size_t len;
    div_t q;

    /*--get user input */
    printf("Enter a fraction (n/d): ");
    if(fgets(strg, 40, stdin) == NULL)  /* process input */
    {
        theGoodEnding();                /* NO_VALUE */
        return(EXIT_SUCCESS);
    }
    len = strlen(strg) - 2;             /* cr/lf nope throway */
    if((int)len < 0)
    {
        theGoodEnding();
        return(EXIT_SUCCESS);
    }else if(isdigit(strg[0]))
    {
        for(t = 0; t <= len; t++)
        {
            if(isdigit(strg[t])) {}     /* it has to be the # or '/' */
            else if(strg[t] == '/') slashcnt++;
            else
            {
                simp_usage();
                return(EXIT_FAILURE);
            }
        }
        if(slashcnt != 1)
        {
            simp_usage();
            return(EXIT_FAILURE);
        }
    }else
    {
        simp_usage();
        return(EXIT_FAILURE);
    }
    rv += sscanf(strg, "%d/%d", &num, &den);

    /*--calculations
     * find the gcf of numerator and denominator
     * then divide both the numerator and denominator by the GCF
     */
    if(num > 0 && den > 0)
    {
        ngcf = gcf(num, den);
        if(ngcf == 1)
        {
            /*--nothing can be done */
            puts("It's already simplified.");
        }else
        {
            q = div(num, ngcf);
            newNum = q.quot;        /* newNum = num / ngcf */
            q = div(den, ngcf);
            newDen = q.quot;        /* newDen = den / ngcf */

            /*--results */
            printf("Simplification........: %d/%d\n", newNum, newDen);
        }
        return(EXIT_SUCCESS);
    }else simp_usage();
    // puts("You may ask yourself: \"How did I get here?\"");
    return(EXIT_FAILURE);
}
