CC = gcc
RM = rm -f
CCFLAGS = -Os#-Wall
M = -lm
PREFIX = /usr/local
FORM = -lform
CURSES = -lncurses

all: hamule

hamule:
#	$(CC) $(CCFLAGS) -o bias bias.c $(M)
	$(CC) -o boost boost.c
	$(CC) $(CCFLAGS) -o clod clod.c $(M)
	$(CC) $(CCFLAGS) -o 'clod (base loaded)' 'clod (base loaded).c' $(M)
	$(CC) $(CCFLAGS) -o elcut elcut.c
#	$(CC) $(CCFLAGS) -o formvar formvar.c $(FORM) $(CURSES)
	$(CC) $(CCFLAGS) -o gainmargin gainmargin.c $(M)
	$(CC) $(CCFLAGS) -o hb hb.c $(M)
	$(CC) $(CCFLAGS) -o hae4guys hae4guys.c $(M)
	$(CC) $(CCFLAGS) -o haeguys haeguys.c $(M)
	$(CC) $(CCFLAGS) -o joules joules.c $(M)
	$(CC) $(CCFLAGS) -o lpda lpda.c $(M)
	$(CC) $(CCFLAGS) -o moxon moxon.c $(M)
	$(CC) $(CCFLAGS) -o rcfilt rcfilt.c $(M)
	$(CC) $(CCFLAGS) -o seriesw seriesw.c $(M)
	$(CC) $(CCFLAGS) -o salkey salkey.c $(M)
	$(CC) $(CCFLAGS) -o tankfreq tankfreq.c $(M)
	$(CC) $(CCFLAGS) -o tanklc tanklc.c $(M)
	$(CC) $(CCFLAGS) -o valfind valfind.c
	$(CC) $(CCFLAGS) -o zipz zipz.c $(M)
	$(CC) $(CCFLAGS) -o zout zout.c

install:
#	cp ./bias $(PREFIX)/bin
	cp ./boost $(PREFIX)/bin
	cp ./clod $(PREFIX)/bin
	cp ./'clod (base loaded)' $(PREFIX)/bin
	cp ./elcut $(PREFIX)/bin
#	cp ./formvar $(PREFIX)/bin
	cp ./gainmargin $(PREFIX)/bin
	cp ./hae4guys $(PREFIX)/bin
	cp ./haeguys $(PREFIX)/bin
	cp ./hb $(PREFIX)/bin
	cp ./joules $(PREFIX)/bin
	cp ./lpda $(PREFIX)/bin
	cp ./moxon $(PREFIX)/bin
	cp ./rcfilt $(PREFIX)/bin
	cp ./seriesw $(PREFIX)/bin
	cp ./salkey $(PREFIX)/bin
	cp ./tankfreq $(PREFIX)/bin
	cp ./tanklc $(PREFIX)/bin
	cp ./valfind $(PREFIX)/bin
	cp ./zipz $(PREFIX)/bin
	cp ./zout $(PREFIX)/bin

clean:
#	$(RM) bias
	$(RM) boost
	$(RM) clod
	$(RM) 'clod (base loaded)'
	$(RM) elcut
#	$(RM) formvar
	$(RM) gainmargin
	$(RM) hae4guys
	$(RM) haeguys
	$(RM) hb
	$(RM) joules
	$(RM) lpda
	$(RM) moxon
	$(RM) rcfilt
	$(RM) seriesw
	$(RM) salkey
	$(RM) tankfreq
	$(RM) tanklc
	$(RM) valfind
	$(RM) zipz
	$(RM) zout

distclean: clean

