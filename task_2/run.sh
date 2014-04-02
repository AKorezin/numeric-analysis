#!/bin/sh
infile=data.txt
outfile=out.txt
echo "$(cat $infile)"
echo -e "./app* $infile $outfile"
./app* $infile $outfile
echo "$(cat $outfile)"
rm $outfile
