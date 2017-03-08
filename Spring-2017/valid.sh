#!/bin/bash

count=$(find ./$1/data -maxdepth 1 -type f|wc -l)
Cases=$((count / 2))

g++ $1/validator.cpp -DSINGLE_FILE -o $1/validator

for ((i=1; i<=Cases; i++)); do
   infile="$1/data/test$i.in"
   echo "Trying $i..."
   $1/./validator < $infile
done

rm $1/validator
