static const struct calc {
    int nr;
    char *name;
} calcs[] =
{
    { 98, "?"          },
    {  1, "bclod"      },
    {  2, "boost"      },
    {  3, "bucks"      },
    {  4, "clod"       },
    {  5, "ctor"       },
    {  6, "dilu"       },
    {  7, "dist"       },
    {  8, "elcut"      },
    { 99, "exit"       },
    {  9, "floyd"      },
    { 10, "gainmargin" },
    { 11, "hae4guys"   },
    { 12, "haeguys"    },
    { 13, "hb"         },
    { 14, "joules"     },
    { 15, "lpda"       },
    { 16, "moxon"      },
    { 17, "nib"        },
    { 18, "pinh"       },
    { 19, "rcfilt"     },
    { 20, "salkey"     },
    { 21, "seriesw"    },
    { 22, "simp"       },
    { 23, "tankfreq"   },
    { 24, "tanklc"     },
    { 25, "valfind"    },
    { 26, "volavg"     },
    { 27, "zipz"       },
    { 28, "zout"       },
};

#define nr_of_calcs (sizeof(calcs)/sizeof(calcs[0]))

#if defined (__VBCC__) || defined (__WATCOMC__)
#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi */
#endif
#endif
