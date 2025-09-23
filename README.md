# hamule
A collection of calculators for amateur radio and electronics
## hamule is HAM calcULators
Hamule descends from the other great calculator projects like hamcalc. We run it instead from the terminal window or shell command prompt. Modern and up to date functions of the C library make it nice to read and clean the code a little bit. Maybe we make it easier for the estudents to understand.

There is a tendency lately to have online calculators for most things. This is good from the standpoint of online availability and they will work in most web browsers. Some of them however do not have world readable code which can be a problem in terms of second hand verifiability of their algorithms. Even those that do will usually use javascript and it can be difficult to find where exactly that code is and what exactly it is doing. There is an argument to be made for the relative privacy of offline 'number crunching'. The Internet may at times be unreliable or web servers or even entire portions of the Internet have become temporarily unavailable more than once. This goes along with a whole host of other issues best left for another discussion another day. For these reasons and others I cannot begin to comprehend, I propose a suite of native compilable CLI calculator programs writen in the C language. CLI because nearly all computer systems, including the so-caled 'legacy' systems, if you like to fool around with that stuff, have one. C because, well I know C, but also because it allows self contained headerless code which makes examination by persons unfarmiliar with the specific application suite relatively easy. In other words you hopefully can better trust the results of the calculation because you can see the algorithm producing them. There is also less opportunity for mistakes than entering them manually into a calculator. This is why even some relatively simple ones have been included.
### Shell Scripting
The design for shell to chain them together and pipe between programs was there from the start. We make the example in maidhb.sh for you to see how it can convert from the maidenhead square to WGS84 lat/long to be use in 'hb' to find the compass heading. This way the output of one program can take as the input to other ones. We make them shell scripting friendly.
### Compile and run
Cloning the repo and issuing the  $ make in the directory will build it for you most of the programs. Maidenhead converter 'maids.c' will need the library, see below.
### The Calculators
* boost.c      - boost converters, find L, duty cycle, filter cap, etc.
* clod.c       - coil loaded verticals or dipoles, variable coil position, center loded for example
* clod (base loaded).c - base loading only, not very ideal but much simpler
* elcut.c      - element cutting, a tuning aid to find how much to cut off
* formvar.c    - user interface for entering data into calculators
* gainmargin.c - critical gain margin calculator for crystal oscillators
* hae4guys.c   - guy wires calculator for 4 guys
* haeguys.c    - guy wires calculator for 3 guys
* hb.c         - use latitude/longitude of remote station to help point the antenna
* joules.c     - Joule energy calc
* lpda.c       - Log-Periodic antenna
* maids.c      - convert to/from maidenhead locator, needs maidenhead library https://github.com/sp6q/maidenhead see maids.c
* moxon.c      - Moxon antennas get dimensions
* rcfilt.c     - RC filter calc
* salkey.c     - Sallen-Key filter
* seriesw.c    - potentiometer resistance and wattage, helps reduce the chance of 'pot burnout'
* tankfreq.c   - calculates LC tank resonant frequency given L and C values
* tanklc.c     - finds L or C that will produce a specific tank resonance frequency
* valfind.c    - LM317 resistor divider to obtain a desired output voltage
* zipz.c       - open wire line impedance calculator
* zout.c       - finds amplifier output impedance using 2 resistors and output voltage
### What needs to be done
* Find series and parallel resistor combinations based on an input resistance value
* Transformer winding calc: how many conductor turns fit through holes in cores
