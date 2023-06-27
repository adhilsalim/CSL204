#!/bin/bash

# to find the sum of natural numbers

echo "enter a number"
read n

i=0
sum=0

while [ $i -le $n ]
do
    sum=$((sum + i))
    i=$((i + 1))
done

echo "sum of $n natural numbers is $sum"