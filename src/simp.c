/* Simplify some fractions
 * Project Crew™ 9/18/2026
 *
 * gcf() source - https://stackoverflow.com/a/44670823
 * Posted by Bill Tarbell
 * Retrieved 2026-09-18, License - CC BY-SA 3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void
usage()
{
    puts("\nYou can't do that!  It's gotta be 2 positive integers "
         "separated by a forward\n"
         "slash.");
    exit(EXIT_FAILURE);
}

void
theGoodEnding()
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


int
main (int argc, const char * argv[])
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
    }
    len = strlen(strg) - sizeof "\n";  /* cr/lf nope throway */
    if(len == 0)
    {
        theGoodEnding();
    }else if(isdigit(strg[0]))
    {
        for(t = 0; t <= len; t++)
        {
            if(isdigit(strg[t])) {}     /* it has to be the # or '/' */
            else if(strg[t] == '/') slashcnt++;
            else usage();
        }
        if(slashcnt != 1) usage();
    }else usage();
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
        exit(EXIT_SUCCESS);
    }else usage();
    puts("You may ask yourself: \"How did I get here?\"");
    return(EXIT_FAILURE);
}
