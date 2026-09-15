CC      = gcc
STRIP   = strip -s
RM      = rm -f
CCFLAGS = -Os#-Wall
M       = -lm
SYNO    = -fsyntax-only

SRCDIR  = src/
PREFIX  = /usr/local
FORM    = -lform
CURSES  = -lncurses

all: hamule

hamule:
# compile
#	$(CC) $(CCFLAGS) -o bias ${SRCDIR}bias.c $(M)
	$(CC) $(CCFLAGS) -o bclod ${SRCDIR}bclod.c $(M)
	$(CC) $(CCFLAGS) -o clod ${SRCDIR}clod.c $(M)
	$(CC) $(CCFLAGS) $(SYNO) -o boost ${SRCDIR}boost.c
	$(CC) $(CCFLAGS) -o bucks ${SRCDIR}bucks.c
	$(CC) $(CCFLAGS) -o dist ${SRCDIR}dist.c $(M)
	$(CC) $(CCFLAGS) -o elcut ${SRCDIR}elcut.c
	$(CC) $(CCFLAGS) -o floyd ${SRCDIR}floyd.c
#	$(CC) $(CCFLAGS) -o formvar formvar.c $(FORM) $(CURSES)
	$(CC) $(CCFLAGS) -o gainmargin ${SRCDIR}gainmargin.c $(M)
	$(CC) $(CCFLAGS) -o hb ${SRCDIR}hb.c $(M)
	$(CC) $(CCFLAGS) -o hae4guys ${SRCDIR}hae4guys.c $(M)
	$(CC) $(CCFLAGS) -o haeguys ${SRCDIR}haeguys.c $(M)
	$(CC) $(CCFLAGS) -o joules ${SRCDIR}joules.c $(M)
	$(CC) $(CCFLAGS) -o lpda ${SRCDIR}lpda.c $(M)
	$(CC) $(CCFLAGS) -o moxon ${SRCDIR}moxon.c $(M)
	$(CC) $(CCFLAGS) -o nib ${SRCDIR}nib.c $(M)
	$(CC) $(CCFLAGS) -o pinh ${SRCDIR}pinh.c $(M)
	$(CC) $(CCFLAGS) -o rcfilt ${SRCDIR}rcfilt.c $(M)
	$(CC) $(CCFLAGS) -o seriesw ${SRCDIR}seriesw.c $(M)
	$(CC) $(CCFLAGS) -o salkey ${SRCDIR}salkey.c $(M)
	$(CC) $(CCFLAGS) -o tankfreq ${SRCDIR}tankfreq.c $(M)
	$(CC) $(CCFLAGS) -o tanklc ${SRCDIR}tanklc.c $(M)
	$(CC) $(CCFLAGS) -o valfind ${SRCDIR}valfind.c
	$(CC) $(CCFLAGS) -o volavg ${SRCDIR}volavg.c $(M)
	$(CC) $(CCFLAGS) -o zipz ${SRCDIR}zipz.c $(M)
	$(CC) $(CCFLAGS) -o zout ${SRCDIR}zout.c
# strip
	$(STRIP) bclod
	$(STRIP) boost
	$(STRIP) bucks
	$(STRIP) clod
	$(STRIP) dist
	$(STRIP) elcut
	$(STRIP) floyd
	$(STRIP) gainmargin
	$(STRIP) hae4guys
	$(STRIP) haeguys
	$(STRIP) hb
	$(STRIP) joules
	$(STRIP) lpda
	$(STRIP) moxon
	$(STRIP) nib
	$(STRIP) pinh
	$(STRIP) rcfilt
	$(STRIP) salkey
	$(STRIP) seriesw
	$(STRIP) tankfreq
	$(STRIP) tanklc
	$(STRIP) valfind
	$(STRIP) volavg
	$(STRIP) zipz
	$(STRIP) zout

install:
#	cp ./bias $(PREFIX)/bin
	cp ./boost $(PREFIX)/bin
	cp ./clod $(PREFIX)/bin
	cp ./bclod $(PREFIX)/bin
	cp ./bucks $(PREFIX)/bin
	cp ./dist $(PREFIX)/bin
	cp ./elcut $(PREFIX)/bin
	cp ./floyd $(PREFIX)/bin
#	cp ./formvar $(PREFIX)/bin
	cp ./gainmargin $(PREFIX)/bin
	cp ./hae4guys $(PREFIX)/bin
	cp ./haeguys $(PREFIX)/bin
	cp ./hb $(PREFIX)/bin
	cp ./joules $(PREFIX)/bin
	cp ./lpda $(PREFIX)/bin
	cp ./moxon $(PREFIX)/bin
	cp ./nib $(PREFIX)/bin
	cp ./pinh $(PREFIX)/bin
	cp ./rcfilt $(PREFIX)/bin
	cp ./seriesw $(PREFIX)/bin
	cp ./salkey $(PREFIX)/bin
	cp ./tankfreq $(PREFIX)/bin
	cp ./tanklc $(PREFIX)/bin
	cp ./valfind $(PREFIX)/bin
	cp ./volavg $(PREFIX)/bin
	cp ./zipz $(PREFIX)/bin
	cp ./zout $(PREFIX)/bin

clean:
#	$(RM) bias
	$(RM) boost
	$(RM) clod
	$(RM) bclod
	$(RM) bucks
	$(RM) dist
	$(RM) elcut
	$(RM) floyd
#	$(RM) formvar
	$(RM) gainmargin
	$(RM) hae4guys
	$(RM) haeguys
	$(RM) hb
	$(RM) joules
	$(RM) lpda
	$(RM) moxon
	$(RM) nib
	$(RM) pinh
	$(RM) rcfilt
	$(RM) seriesw
	$(RM) salkey
	$(RM) tankfreq
	$(RM) tanklc
	$(RM) valfind
	$(RM) volavg
	$(RM) zipz
	$(RM) zout

distclean: clean

