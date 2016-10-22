#!/bin/bash

Cases=$2

g++ -std=c++11 $1/solution.cpp -DSINGLE_FILE -o $1/solution

for ((i=1; i<=Cases; i++)); do
   infile="$1/data/test$i.in"
   outfile="$1/data/test$i.ans"
   ($1/./solution < $infile) > $1/temp
   echo "Trying $i..."
   diff $1/temp $outfile
done

rm $1/temp
rm $1/solution
