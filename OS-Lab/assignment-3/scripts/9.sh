#!/bin/bash

arr=('e1' 'e2' 'e3' 'e4' 'e5' 'e6')
echo "${arr[@]}"

arr=('e1' 'e2' 'e3' 'e4' 'e5' 'e6')
arr=("${arr[@]:0:2}" "${arr[@]:3}")

echo "${arr[@]}"
