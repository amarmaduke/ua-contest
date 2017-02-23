#!/bin/bash

count=$(find ./$1/data -maxdepth 1 -type f|wc -l)
Cases=$((count / 2))

g++ $1/solution.cpp -DSINGLE_FILE -o $1/solution

for ((i=1; i<=Cases; i++)); do
   infile="$1/data/test$i.in"
   outfile="$1/data/test$i.ans"
   ($1/./solution < $infile) > $1/temp
   echo "Trying $i..."
   diff $1/temp $outfile
done

rm $1/temp
rm $1/solution
