#!/bin/sh
infile=data.txt
outfile=out.txt
cat $infile
echo ./app* $infile $outfile
./app* $infile $outfile
cat $outfile
rm $outfile
