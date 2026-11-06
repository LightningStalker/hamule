#if !defined M_PI
#ifndef M_PI
#define M_PI		3.14159265358979323846	/* pi */
#endif
#endif

#define R        6371e3                 /* mean radius of Earth in meaters */
#define M_C      299792458              /* speed of light */

#if defined (__DOS__)
#define DEGSYM  "\xf8"    // o
#define LESYM   "\xf3"    // <=
#define MUSYM   "\x00e6"  // u
#define OMEGA   "\xea"    // ohm
#define SUB2    "_2"      // subscript 2
#define SUBM    "(m)"     // subscript m
#define TAU     "\xe7"    // t
#else
#define DEGSYM  "\u00b0"                     /* differences of the codepage */
#define LESYM   "\u2266"
#define MUSYM   "\u00b5"
#define OMEGA   "\u2126"
#define SUB2    "\u2082"
#define SUBM    "\u2098"
#define TAU     "\03c4"
#endif

#if defined (__GNUC__)
#define MAX(x, y) ( \
        { __auto_type __x = (x); __auto_type __y = (y); \
          __x > __y ? __x : __y; })
#endif
