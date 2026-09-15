/* parser for hamule
 *
 * Project Crew™ 7/10/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
    char *strg = NULL;
    size_t alocsz;
    ssize_t len;

    printf("hamule v0.01\n"
           "Type `?` to get help.\n"
           "# ");
    while((len = getline(&strg, &alocsz, stdin)) >= 0)
    {
        if(strcmp(strg, "exit\n") == 0)
        {
            free(strg);
            exit(EXIT_SUCCESS);
        }else if(strcmp(strg, "?\n") == 0)
        {
            puts("help text");
        }
        printf("# ");
    }
    puts("\nexit");
    free(strg);
    exit(EXIT_SUCCESS);
}
