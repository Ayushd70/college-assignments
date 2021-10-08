#!/bin/bash

read -r -p "Enter file name: " f
read -r -p "Enter line start: " l
read -r -p "Enter line end: " e
more +"$l" -"$e" "$f"
