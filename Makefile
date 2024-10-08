CC = gcc
RM = rm -f
CCFLAGS = -Wall
M = -lm
PREFIX = /usr/local

all: hamule

hamule:
#	$(CC) $(CCFLAGS) -o bias bias.c $(M)
	$(CC) $(CCFLAGS) -o boost boost.c
	$(CC) $(CCFLAGS) -o clod clod.c $(M)
	$(CC) $(CCFLAGS) -o 'clod (base loaded)' 'clod (base loaded).c' $(M)
	$(CC) $(CCFLAGS) -o elcut elcut.c
	$(CC) $(CCFLAGS) -o gainmargin gainmargin.c $(M)
	$(CC) $(CCFLAGS) -o joules joules.c $(M)
	$(CC) $(CCFLAGS) -o rcfilt rcfilt.c $(M)
	$(CC) $(CCFLAGS) -o seriesw seriesw.c $(M)
	$(CC) $(CCFLAGS) -o salkey salkey.c $(M)
	$(CC) $(CCFLAGS) -o tankfreq tankfreq.c $(M)
	$(CC) $(CCFLAGS) -o tanklc tanklc.c $(M)
	$(CC) $(CCFLAGS) -o valfind valfind.c
	$(CC) $(CCFLAGS) -o zipz zipz.c -lm
	$(CC) $(CCFLAGS) -o zout zout.c

install:
#	cp ./bias $(PREFIX)/bin
	cp ./boost $(PREFIX)/bin
	cp ./clod $(PREFIX)/bin
	cp ./'clod (base loaded)' $(PREFIX)/bin
	cp ./elcut $(PREFIX)/bin
	cp ./gainmargin $(PREFIX)/bin
	cp ./joules $(PREFIX)/bin
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
	$(RM) gainmargin
	$(RM) joules
	$(RM) rcfilt
	$(RM) seriesw
	$(RM) salkey
	$(RM) tankfreq
	$(RM) tanklc
	$(RM) valfind
	$(RM) zipz
	$(RM) zout

distclean: clean

