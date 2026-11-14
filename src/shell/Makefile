TARGETDIR  := ../../
TESTDIR    := ../../test
TRGFRTEST  := ../
TARGET     := hamule
TARGET_EXE := HAMULE.EXE
TEST       := test.txt
RESULT     := result.txt
SUM        := sum.sha256

WATCOM     := ~/Downloads/dos/watcom
INCLUDE    := $(WATCOM)/h
PATHENV    := $(shell echo $$PATH)
PATH       := $(WATCOM)/binl:$(PATHENV)
ENV        := WATCOM=$(WATCOM) INCLUDE=$(INCLUDE) PATH=$(PATH)

LDLIBS  := -lm
EXEFILE := -fe=

STRIP   := strip
RM      := rm -f
LS      := ls -l
SUMPROG := sha256sum

SUMOPTS := -c

# objects fiel
OBJECTS :=   \
bclod.o      \
boost.o      \
bucks.o      \
clod.o       \
ctor.o       \
dilu.o       \
dist.o       \
elcut.o      \
func.o       \
gainmargin.o \
getline.o    \
hae4guys.o   \
haeguys.o    \
hb.o         \
joules.o     \
lpda.o       \
moxon.o      \
nib.o        \
parsin.o     \
pinh.o       \
rcfilt.o     \
salkey.o     \
seriesw.o    \
simp.o       \
tankfreq.o   \
tanklc.o     \
valfind.o    \
zipz.o       \
zout.o

all: $(TARGETDIR)$(TARGET)

dos: $(TARGETDIR)$(TARGET_EXE)

# GNU
$(TARGETDIR)$(TARGET): CC     := gcc
$(TARGETDIR)$(TARGET): CFLAGS := -Os
$(TARGETDIR)$(TARGET): $(OBJECTS)
	$(RM) $(TARGET)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	$(STRIP) -s $@
	$(LS) $@

# Watcom
$(TARGETDIR)$(TARGET_EXE): CC     := $(ENV) wcl
$(TARGETDIR)$(TARGET_EXE): CFLAGS := -bt=dos -q -wx
$(TARGETDIR)$(TARGET_EXE): OUTPUT_OPTION :=
$(TARGETDIR)$(TARGET_EXE): $(OBJECTS)
	$(RM) $@
	$(CC) $(CFLAGS) $^ $(EXEFILE)$@

bclod.o      : bclod.c bclod.h define.h
boost.o      : boost.c boost.h define.h
bucks.o      : bucks.c bucks.h define.h
clod.o       : clod.c clod.h define.h
ctor.o       : ctor.c ctor.h
dilu.o       : dilu.c dilu.h func.c func.h
dist.o       : dist.c dist.h define.h func.c func.h
elcut.o      : elcut.c elcut.h
gainmargin.o : gainmargin.c gainmargin.h
getline.o    : getline.c getline.h
hae4guys.o   : hae4guys.c hae4guys.h define.h
haeguys.o    : haeguys.c haeguys.h define.h
hb.o         : hb.c hb.h define.h func.c func.h
func.o       : func.c func.h
joules.o     : joules.c joules.h
lpda.o       : lpda.c lpda.h define.h
moxon.o      : moxon.c moxon.h define.h
nib.o        : nib.c nib.h
parsin.o     : parsin.c parsin.h define.h func.c func.h getline.c getline.h
pinh.o       : pinh.c pinh.h
rcfilt.o     : rcfilt.c rcfilt.h define.h
salkey.o     : salkey.c salkey.h define.h
seriesw.o    : seriesw.c seriesw.h define.h
simp.o       : simp.c simp.h func.c func.h
tankfreq.o   : tankfreq.c tankfreq.h define.h
tanklc.o     : tanklc.c tanklc.h define.h
valfind.o    : valfind.c valfind.h define.h
zipz.o       : zipz.c zipz.h define.h
zout.o       : zout.c zout.h

test:
	@cd $(TESTDIR) && \
	$(TRGFRTEST)$(TARGET) < $(TEST) &> $(RESULT) && \
	$(SUMPROG) $(SUMOPTS) $(SUM) && \
	echo Tests pass || \
	echo Some tests may have failed. Check $(RESULT)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)

distclean: clean
	$(RM) $(TARGETDIR)$(TARGET) $(TARGETDIR)$(TARGET_EXE)
