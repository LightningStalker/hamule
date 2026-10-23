#!/bin/bash
gcc -Wall -Os -o hamule parsin.c joules.c pinh.c seriesw.c tankfreq.c \
  tanklc.c -lm
strip -s hamule
ls -l hamule
