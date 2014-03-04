#!/bin/sh
infile=data.txt
outfile=out.txt
./app* $infile $outfile
cat $outfile
