/* generate the pink noise
 * depend: Tom Merchant's Voss-McCartney pink-noise approximation algorithm:
 * (https://gist.github.com/tom-merchant/5ced03a0638b06138ee7d11c0c209aa4)
 *
 * Project Crew™ 2/4/2026
 */

#define PROGNAME    "floyd"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <termios.h>
#include <fcntl.h>

#include "pinknoise.c"
/*
#define DEBUG   1
*/

void
usage()
{
    fputs(
        "\n"
        "  "PROGNAME" is a pink noise generator who is borrowing Tom Merchant's\n"
        "    Voss-McCartney pink-noise approximation algorithm.\n"
        "\n"
        "  Output is raw FLOAT_LE (32-bit) sample.\n"
        "\n"
        "  Usage:  $ "PROGNAME" [SECONDS] [redirect/pipe]\n"
        "\n"
        "  Example: "PROGNAME" 3 > sndfile.raw\n"
        "\n"
        "  Output should be 3 seconds of the pink noise (for samplerate = 44100s/sec).\n"
        "\n"
        "  If you run " PROGNAME" without args, he will keep going.\n"
        "  You can press a key to stop the " PROGNAME".\n"
        "  That mean you can do something like:\n"
        "\n"
        "    $ " PROGNAME" | aplay -f FLOAT_LE -r 44100\n"
        "\n"
        "    and get the noise for a while.\n"
        "\n"
        "  (http://en.wikipedia.org/Pink_Noise)\n"
        "  Project Crew™ 2026\n",
        stderr);
#if defined (__GNUC__)
        putc('\n', stderr);
#endif
}

/* some global struct */
struct termios
termios,
termstateorig,
*termios_p = &termios,
*termstateorig_p = &termstateorig;

/* set term input raw, nonblocking */
void
termSetup()
{
    tcgetattr(STDIN_FILENO, termios_p);
    termstateorig = termios;
    cfmakeraw(termios_p);
    tcsetattr(STDIN_FILENO, TCSANOW, termios_p);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

/* restore term state and exit */
void
termRestore()
{
    tcsetattr(STDIN_FILENO, TCSANOW, termstateorig_p);
    fcntl(STDIN_FILENO, F_SETFL, !O_NONBLOCK);
}

int
main(int argc, char *argv[])
{
    pink osc;
    float out[1];
    uint16_t crnow = 0xdadd;            /* var to return the carriage */
    int cc, c,
        d, time = 0;                    /* duration, timer on/off */

    if(argc > 1)                        /* arg parsing */
    {
        time = atoi(argv[1]);
#ifdef  DEBUG
        fprintf(stderr, "%i\n", time);
#endif
        if(time == 0)
        {
            for(int i = 0; i < strlen(argv[1]); i++)
            {
                if(isalpha(argv[1][i]) || ispunct(argv[1][i]))
                {
                    usage();
                    exit(1);
                }
            }
            d = 0;                      /* sets infinite for loop */
            time = 1;
        }else if(time < 0)
        {
            time ^= -1;                 /* flip sign */
            time++;
            d = 1;                      /* regular for loop */
        }else
        {
            d = 1;
        }
    }else
    {
        d = 0;                          /* no args so infinite loop */
        time = 1;
    }
#ifdef  DEBUG
    fprintf(stderr, "%i, %i\n", time, d);
#endif

    termSetup();                        /* raw nonblocking input */
    init_pink_noise_gen(&osc);          /* bring the noise */

    for(cc = 0; cc < time; cc += d)
    {
        for(c = 0; c < 44100; c++)      /* the Joy of division */
        {
            out[0] = pink_noise_next(&osc);
            fwrite(out, sizeof(float), 1, stdout);
            if(!crnow)
                fputs("\r", stderr);
            crnow++;
            if(getchar() > 0)           /* check the key */
            {
                termRestore();
                fputs(PROGNAME": exiting...\n\r", stderr);
                exit(EXIT_SUCCESS);
            }
        }
    }
    termRestore();
}
