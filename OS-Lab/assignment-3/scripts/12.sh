#!/bin/bash

read -r -p "Enter 1st number: " n1
read -r -p "Enter 2nd number: " n2
read -r -p "Enter 3rd number: " n3

for i in $n1 $n2 $n3; do
    for j in $n1 $n2 $n3; do
        for k in $n1 $n2 $n3; do
            echo "$i" "$j" "$k"
        done
    done
done
