#!/bin/bash

read -r num
fact=1

for ((i = 2; i <= num; i++)); do
    fact=$((fact * i))
done

echo $fact
