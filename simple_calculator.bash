#!/bin/bash

function add()
{
    echo "sum is $(($1+$2))"
}

function sub()
{
    echo "difference is $(($1-$2))"
}

function mul()
{
    echo "product is $(($1*$2))"
}

function div()
{
    echo "quotient is $(($1/$2))"
}

exitfromloop=0
while [ $exitfromloop -ne 1 ]
do
    echo "simple calculator"

    echo "enter first number"
    read num1

    echo "enter second number"
    read num2

    echo "MENU"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    read choice

    case $choice in
        1) add $num1 $num2 ;;
        2) sub $num1 $num2 ;;
        3) mul $num1 $num2 ;;
        4) div $num1 $num2 ;;
        5) exitfromloop=1 ;;
        *) echo "invalid choice" ;;
    esac
done

echo "exiting program"

