#if defined (__VBCC__) || defined (__WATCOMC__)
#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi */
#endif
#endif

#if defined (__DOS__)
#define MUSYM       "\x00e6"
#else
#define MUSYM       "\u00b5"
#endif

#if defined (__DOS__)
#define OMEGA   "\xea"
#else
#define OMEGA   "\u2126"                     /* differences of the codepage */
#endif
