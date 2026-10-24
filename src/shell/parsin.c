/* parser shell for hamule
 *
 * Project Crew™ 7/10/2026
 */

#define VER         "0.01"
#define PROGNAME    "parsin"
#define PROJ        "hamule"

#include "define.h"
#include "parsin.h"

#include "joules.h"
#include "pinh.h"
#include "seriesw.h"
#include "tankfreq.h"
#include "tanklc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LF  10

enum { kMaxArgs = 64 };
char *avec[kMaxArgs];

/* Source - https://stackoverflow.com/a/13281447
 * Posted by sstteevvee, modified by community.
 * See post 'Timeline' for change history
 * Retrieved 2026-10-19, License - CC BY-SA 3.0
 */
int
strtoargs(char *commandLine[], ssize_t *len)
{
    int acnt = 0;

    *(*commandLine + *len - 1) = 0;          /* line feed char is a 0 */

    char *p2 = strtok(*commandLine, " ");    /* hey sstteevvee        */
    while (p2 && acnt < kMaxArgs-1)
    {
        avec[acnt++] = p2;
        p2 = strtok(0, " ");
    }
    avec[acnt] = 0;
    return(acnt);
}

static int
compmi(const void *m1, const void *m2)
{
    const struct calc *mi1 = m1;
    const struct calc *mi2 = m2;
    return strcmp(mi1->name, mi2->name);
}

void
showhelp()
{
    int t;

    puts("\nThe calculators are:");
    for(t = 0; t < nr_of_calcs; t++)
    {
        printf("%-20s", calcs[t].name);
    }
    puts("\n  * not all are include yet this shell version of the hamule.");
}



int
main(int argc, char *argv[])
{
    int     //t,
            acnt;
    char   *strg = NULL;
    size_t  alocsz = 0;
    ssize_t len;
    struct calc key;
    struct calc *res;

/* we already sort him */
/*    qsort(calcs, nr_of_calcs, sizeof(calcs[0]), compmi);*/
    printf(PROJ" v"VER"\n"
           "Type `?` to get help.\n"
           "# ");
    while((len = getline(&strg, &alocsz, stdin)) >= 0)
    {
        acnt = strtoargs(&strg, &len);       /* make the argc/argv */
        /* print debug */
        /* printf("acnt = %i\n", acnt);
        for(t = 0; t < acnt; t++)
        {
            printf("argv[%i]: %s\n", t, avec[t]);
        }
        // * end print debug    */

        /* bsearch to find calc */
        if(acnt > 0)
        {
            key.name = avec[0];
            res = bsearch(&key, calcs, nr_of_calcs,
                          sizeof(calcs[0]), compmi);
            /*if (res == NULL)
                printf("'%s': unknown calc\n", avec[0]);
            else
                printf("%s: calc #%d\n", res->name, res->nr);*/

        /* to do what needs to be done */
            if(res != NULL)
            {
                switch(res->nr)
                {
                    case 13 : joules(acnt, avec);
                              break;

                    case 17 : pinh(acnt, avec);
                              break;

                    case 20 : seriesw(acnt, avec);
                              break;

                    case 22 : tankfreq(acnt, avec);
                              break;

                    case 23 : tanklc(acnt, avec);
                              break;

                    case 98 : showhelp();              // '?'
                              break;

                    case 99 : free(strg);              // "exit"
                              exit(EXIT_SUCCESS);
                              break;

                    default : printf("calc [%s] not done yet\n", res->name);
                }
            }else
            {
                printf("\'%s\' not!found\n", avec[0]);
            }
        }

        printf("# ");
    }
    puts("\nexit");
    free(strg);
    exit(EXIT_SUCCESS);
}
