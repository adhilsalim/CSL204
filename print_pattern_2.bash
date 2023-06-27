#!/bin/bash

echo "enter a number"
read number

for((i=1;i<=number;i++))
do
    for((j=1;j<=i;j++))
    do
        echo -n "$j "
    done
    echo ""
done