#!/bin/bash
PROGNAME=$(basename ${0})
find -maxdepth 1 -executable \! -name '*.*' -printf '%f\n' | sort | ascksum > sums.asck
echo -n "${PROGNAME}: Number of duplicates: "
if cat sums.asck | sort | uniq -d | grep -c '0x'
then
  cat sums.asck | sort | uniq -d | xargs -I {} grep -B1 {} sums.asck
else
  echo "${PROGNAME}: None found."
fi
