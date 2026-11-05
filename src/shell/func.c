/* common function
 * Project Crew™ 10/14/2026
 * 
 * gcf() source - https://stackoverflow.com/a/44670823
 * Posted by Bill Tarbell
 * Retrieved 2026-09-18, License - CC BY-SA 3.0
 */

#include <math.h>

#include "func.h"
#include "define.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void
sExit()
{
    puts("\nNo input, exiting...");
    return;
}

void
errdec()
{
    puts("\nMust be decimal numbers.  Units don't matter.");
    return;
}

/* get a floating pinout number */
float
getfl()
{
    static const short int crlf = sizeof "\n";
    char strg[40];
    int len;
    short int t, dotcnt = 0;

    if(fgets(strg, 40, stdin) == NULL)  /* process input */
    {
        sExit();                /* NO_VALUE */
        return 0;
    }
    len = (int)strlen(strg) - crlf;
    if(len >= 0)
    {
        for(t = 0, dotcnt = 0; t <= len; t++)
        {
            //printf("%#.2x\n", strg[t]);
            if(isdigit(strg[t])) {}          /* it has to be numbers */
            else if(strg[t] == '.') dotcnt++;     /* or '.' */
            else errdec();
        }
        if(dotcnt > 1) errdec();
    }else sExit();
    return 0;
}

long
lround(double d) {
    if (d > 0.0) return (long)(d + 0.5);
    else if (d < 0.0) return (long)(d - 0.5);
    else return 0;
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

float
toRadians(float deg)
{
    return M_PI * deg / 180.0;
}
