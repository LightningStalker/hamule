CC = gcc
RM = rm -f
CCFLAGS = -Wall
M = -lm

all: hamule

hamule:
#	$(CC) $(CCFLAGS) -o bias bias.c $(M)
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
#	cp ./bias /usr/local/bin
	cp ./clod /usr/local/bin
	cp ./'clod (base loaded)' /usr/local/bin
	cp ./elcut /usr/local/bin
	cp ./gainmargin /usr/local/bin
	cp ./joules /usr/local/bin
	cp ./rcfilt /usr/local/bin
	cp ./seriesw /usr/local/bin
	cp ./salkey /usr/local/bin
	cp ./tankfreq /usr/local/bin
	cp ./tanklc /usr/local/bin
	cp ./valfind /usr/local/bin
	cp ./zipz /usr/local/bin
	cp ./zout /usr/local/bin

clean:
#	$(RM) bias
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

