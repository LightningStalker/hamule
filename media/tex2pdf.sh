#!/bin/bash
# generate pdf and png from the TeX file
BASE=$(basename -s .tex ${1})
rm -f *.log *.gz *.aux *.dvi
latex2png -m -d 900 ${1}
mogrify -quiet -resize 25% -bordercolor white -border 20 ${BASE}.png
