#!/bin/bash

read -p "Enter how many numbers: " n
sum=0

for (( i=1; i<=n; i++ ))
do
    read -p "Enter number $i: " num
    sum=$((sum + num))
done

echo "Total sum: $sum"
