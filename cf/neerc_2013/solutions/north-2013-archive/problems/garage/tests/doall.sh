#!/bin/bash

i=0
while read test; do
    i=$(($i+1))
    echo "$test" > `printf %02d $i`
done < tests.all

