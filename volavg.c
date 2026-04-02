/* average volume of the audio
 * Project Crew™ 3/16/2026
 */

#define PROGNAME    "volavg"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void
usage()
{
    usleep(1e4);
    fputs("\n"
          "  "PROGNAME" averages 16-bit little endian samples from standard input.\n"
          "    It can help you adjust the volume for sound card processing programs.  We\n"
          "    made it to use the most common sample format.\n"
          "\n"
          "  You need a program like `arecord` who gets the raw sample from sound cards\n"
          "    and can send them to stdout.  That way you can pipe it into "PROGNAME".\n"
          "\n"
          "  Use like this:  $ arecord -f cd -c 1 | "PROGNAME"\n"
          "\n"
          "  Don't forget to use the same sound card input as the SDR program you\n"
          "    adjust the volume for.\n"
          "\n"
          "  Any option passed into "PROGNAME" will show this help.\n"
          "\n"
          "  Output stream of "PROGNAME" will show 2 numbers every line.  First one is the\n"
          "    RMS average of about 50ms samples block (44100sample/second).  The second\n"
          "    one is averaging them for about 6 seconds.  No decibel calculation is\n"
          "    perform.  Use Ctrl+C to quit.\n"
          "\n", stderr);
    exit(EXIT_FAILURE);
}


int
main(int argc, char *argv[])
{
    int16_t in[1];
    unsigned int counta, rms, avg = 0, avgsum = 0;
    unsigned long int sampsqsum = 0;
    short int countb = 0;

    if(argc > 1)
        usage();

/* initial average some samples */
    for(counta = 0; counta < 2048; counta++)
    {
        if(fread(in, sizeof(int16_t), 1, stdin))
            avg += abs(in[0]);
    }
    avg    /= 2048;
    counta ^= counta;

    while(fread(in, sizeof(int16_t), 1, stdin))
    {
        sampsqsum += in[0] * in[0];     /* add square and store */
        if(counta > 2047)
        {
            sampsqsum >>= 11;           /* sampsqsum /= 2048 */
            rms         = (unsigned int)sqrtf(sampsqsum);
            avgsum     += rms;          /* sum for mean value */
            printf("%i, %i\n", rms, avg);
            counta     ^= counta;       /* counta = 0 */
            if(countb > 127)
            {
                avgsum  = avg = avgsum >> 7;      /* average 128 rmss */
                countb ^= countb;
            }
            countb++;
        }
        counta++;
    }
}
