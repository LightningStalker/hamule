CFLAGS := -Os#-Wall
M      := -lm
PREFIX := /usr/local
WNUR   := -Wno-unused-result

FIND    := find
INSTALL := install
RM      := rm -f
STRIP   := strip -s
XARGS   := xargs

FINDOPT    := -maxdepth 1 -type f -executable ! -regex .+\.sh -print0
INSTALLOPT := -o 0 -g 0 -m 755
XARGSOPT   := -0 -I {}

vpath %.c src

all: bclod \
     boost \
     bucks \
     clod \
     dilu \
     dist \
     elcut \
     floyd \
     gainmargin \
     hae4guys \
     haeguys \
     hb \
     joules \
     lpda \
     moxon \
     nib \
     pinh \
     rcfilt \
     salkey \
     seriesw \
     simp \
     tankfreq \
     tanklc \
     valfind \
     volavg \
     zipz \
     zout

bclod: bclod.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

boost: boost.c
	$(CC) $(CFLAGS) $(WNUR) -o $@ $^
	$(STRIP) $@

bucks: bucks.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

clod: clod.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

dilu: dilu.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

dist: dist.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

elcut: elcut.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

floyd: floyd.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

gainmargin: gainmargin.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

hae4guys: hae4guys.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

haeguys: haeguys.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

hb: hb.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

joules: joules.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

lpda: lpda.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

moxon: moxon.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

nib: nib.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

pinh: pinh.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

rcfilt: rcfilt.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

salkey: salkey.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

seriesw: seriesw.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

simp: simp.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

tankfreq: tankfreq.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

tanklc: tanklc.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

valfind: valfind.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

volavg: volavg.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

zipz: zipz.c
	$(CC) $(CFLAGS) -o $@ $^ $(M)
	$(STRIP) $@

zout: zout.c
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@


install:
	$(FIND) $(FINDOPT) | $(XARGS) $(XARGSOPT) $(INSTALL) \
	$(INSTALLOPT) {} $(PREFIX)/bin

clean:
#	$(RM) bias
	$(RM) bclod
	$(RM) boost
	$(RM) bucks
	$(RM) clod
	$(RM) dilu
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
	$(RM) salkey
	$(RM) seriesw
	$(RM) simp
	$(RM) tankfreq
	$(RM) tanklc
	$(RM) valfind
	$(RM) volavg
	$(RM) zipz
	$(RM) zout

distclean: clean