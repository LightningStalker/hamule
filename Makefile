CC = gcc
RM = rm -f
CCFLAGS = -Wall
M = -lm

all: hamule

hamule:
	$(CC) $(CCFLAGS) -o bias bias.c $(M)
	$(CC) $(CCFLAGS) -o clod clod.c $(M)
	$(CC) $(CCFLAGS) -o 'clod (base loaded)' 'clod (base loaded).c' $(M)
	$(CC) $(CCFLAGS) -o elcut elcut.c
	$(CC) $(CCFLAGS) -o joules joules.c $(M)
	$(CC) $(CCFLAGS) -o rcfilt rcfilt.c $(M)
	$(CC) $(CCFLAGS) -o seriesw seriesw.c $(M)
	$(CC) $(CCFLAGS) -o salkey salkey.c $(M)
	$(CC) $(CCFLAGS) -o tankfreq tankfreq.c $(M)
	$(CC) $(CCFLAGS) -o tanklc tanklc.c $(M)
	$(CC) $(CCFLAGS) -o valfind valfind.c
	$(CC) $(CCFLAGS) -o zout zout.c

clean:
	$(RM) bias
	$(RM) clod
	$(RM) 'clod (base loaded)'
	$(RM) elcut
	$(RM) joules
	$(RM) rcfilt
	$(RM) seriesw
	$(RM) salkey
	$(RM) tankfreq
	$(RM) tanklc
	$(RM) valfind
	$(RM) zout

distclean: clean

