#!/bin/bash
# generate pdf and png from the TeX file
BASE=$(basename -s .tex ${1})
pdflatex ${1}
pdftoppm -png -r 300 ${BASE}.pdf > ${BASE}.png