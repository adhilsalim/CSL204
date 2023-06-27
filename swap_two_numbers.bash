#!/bin/bash

echo "enter 1st number"
read a
echo "enter 2nd number"
read b

echo "before swapping a=$a and b=$b"

temp=$a
a=$b
b=$temp

# OR
# a=$((a + b))
# b=$((a - b))
# a=$((a - b))

echo "after swapping a=$a and b=$b"