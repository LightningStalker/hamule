#!/bin/bash
# example of chaining in the suite
# enter maidenhead grids as arguments to lat/long programs

# with xargs
./maids $1 | xargs -L 1 -t bash -c './hb $0 $1 35 135'

# with command substuition
./hb $(./maids $1) $(./maids $2)