/* parser for hamule
 *
 * Project Crew™ 7/10/2026
 */

#define PROGNAME    "hamule"

#include <stdio.h>
#include <stdlib.h>
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


int
main(int argc, char *argv[])
{
    int     t,
            acnt;
    char   *strg = NULL;
    size_t  alocsz;
    ssize_t len;

    printf("hamule v0.01\n"
           "Type `?` to get help.\n"
           "# ");
    while((len = getline(&strg, &alocsz, stdin)) >= 0)
    {
        acnt = strtoargs(&strg, &len);       /* make the argc/argv */
        /* print debug */
        printf("acnt = %i\n", acnt);
        for(t = 0; t < acnt; t++)
        {
            printf("argv[%i]: %s\n", t, avec[t]);
        }
        /* end print debug */
        if(acnt > 0)
        {
            if(strcmp(avec[0], "exit") == 0)
            {
                free(strg);
                exit(EXIT_SUCCESS);
            }else if(strcmp(avec[0], "?") == 0)
            {
                puts("help text");
            }
        }
        printf("# ");
    }
    puts("\nexit");
    free(strg);
    exit(EXIT_SUCCESS);
}
