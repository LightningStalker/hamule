# hamule
A collection of calculators for amateur radio and electronics
## hamule is HAM calcULators
There is a tendency lately to have online calculators for most things. This is good from the standpoint of online availability and they will work in most web browsers. Some of them however do not have world readable code which can be a problem in terms of second hand verifiability of their algorithms. Even those that do will usually use javascript and it can be difficult to find where exactly that code is and what exactly it is doing. There is an argument to be made for the relative privacy of offline 'number crunching'. The Internet may at times be unreliable or web servers or even entire portions of the Internet have become temporarily unavailable more than once. This goes along with a whole host of other issues best left for another discussion another day. For these reasons and others I cannot begin to comprehend, I propose a suite of native compilable CLI calculator programs writen in the C language. CLI because nearly all computer systems, including the so-caled 'legacy' systems, if you like to fool around with that stuff, have one. C because, well I know C, but also because it allows self contained headerless code which makes examination by persons unfarmiliar with the specific application suite relatively easy. In other words you hopefully can better trust the results of the calculation because you can see the algorithm producing them. There is also less opportunity for mistakes than entering them manually into a calculator. This is why even some relatively simple ones have been included.
### The Calculators
* clod.c       - coil loaded verticals or dipoles, variable coil position, center loded for example
* clod (base loaded).c - base loading only, not very ideal but much simpler
* elcut.c      - element cutting, a tuning aid to find how much to cut off
* gainmargin.c - critical gain margin calculator for crystal oscillators
* joules.c     - Joule energy calc
* rcfilt.c     - RC filter calc
* seriesw.c    - potentiometer resistance and wattage, helps reduce the chance of 'pot burnout'
* tankfreq.c   - calculates LC tank resonant frequency given L and C values
* tanklc.c     - finds L or C that will produce a specific tank resonance frequency
* valfind.c    - LM317 resistor divider to obtain a desired output voltage
* zipz.c       - open wire line impedance calculator
* zout.c       - finds amplifier output impedance using 2 resistors and output voltage
### What needs to be done
* Find series and parallel resistor combinations based on an input resistance value
* Transformer winding calc: how many conductor turns fit through holes in cores
