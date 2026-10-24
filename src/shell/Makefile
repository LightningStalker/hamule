TARGET := ../../hamule

CFLAGS := -Wall -Os
LIBS   := -lm

CC     := gcc
STRIP  := strip
RM     := rm

# objects fiel
OBJECTS := \
joules.o   \
parsin.o   \
pinh.o     \
seriesw.o  \
tankfreq.o \
tanklc.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	rm -f $(TARGET)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LIBS)
	#$(STRIP) -s $(TARGET)

joules.o   : joules.c joules.h
parsin.o   : parsin.c parsin.h define.h
pinh.o     : pinh.c pinh.h
seriesw.o  : seriesw.c seriesw.h define.h
tankfreq.o : tankfreq.c tankfreq.h
tanklc.o   : tanklc.c tanklc.h define.h

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJECTS)

distclean: clean
