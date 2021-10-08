#!/bin/bash

echo -e 'Enter the numbers separated by a comma \n> '
read -r string

set -f # avoid globbing (expansion of *).
array=(${string//,/ })

IFS=$'\n'                                      ## only word-split on '\n'
array=($(printf "%s\n" ${array[@]} | sort -r)) ## reverse sort

echo -e "\nMaximum: "
echo "${array[0]}" ## simply output the array

echo -e "\nMinimum: "
echo "${array[-1]}"
