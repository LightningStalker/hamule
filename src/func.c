/* common function
 * Project Crew™ 10/14/2026
 */

#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void
sExit()
{
    puts("\nNo input, exiting...");
    exit(EXIT_SUCCESS);
}

void
errdec()
{
    puts("\nMust be decimal numbers.  Units don't matter.");
    exit(EXIT_FAILURE);
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
    return strtod(strg, NULL);
}
