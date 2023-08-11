#!/bin/bash

i=1
number=4

while [ $i -le $number ]
do
    if [ $i -eq 1 ]; then
        echo "1"
    elif [ $i -eq 2 ]; then
        echo "1 2"
    elif [ $i -eq 3 ]; then
        echo "1 2 3"
    elif [ $i -eq 4 ]; then
        echo "1 2 3 4"
    fi
    i=$((i+1))
done