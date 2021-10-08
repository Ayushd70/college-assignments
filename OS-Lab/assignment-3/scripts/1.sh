#!/bin/bash

echo "Select the task to perform"
echo "1. Merging the contents of two files into another"
echo "2. Searching a pattern from a file."
echo "3. Exit from menu "
echo -n "Enter your menu choice [1-3]: "

while :; do

    # reading choice
    read -r choice

    # case statement is used to compare one value with the multiple cases.
    case $choice in
    # Pattern 1
    1)
        echo "You have selected the option 1"
        echo "Enter the file names to be merged"
        echo -n "Enter the first file name: "
        read -r file1
        echo -n "Enter the second file name: "
        read -r file2
        echo "The contents of the two files are being merged"
        cat "$file1" "$file2" >merged.txt
        echo "The merged file is created successfully"
        echo "The contents of the merged file are:"
        cat merged.txt
        ;;
    # Pattern 2
    2)
        echo "You have selected the option 2"
        echo "Enter the file name to be searched"
        echo -n "Enter the file name: "
        read -r file3
        echo "Enter the pattern to be searched"
        echo -n "Enter the pattern: "
        read -r pattern
        echo "The pattern is being searched in the file"
        grep "$pattern" "$file3"
        ;;
    # Pattern 3
    3)
        echo "Quiting ..."
        exit
        ;;
    # Default Pattern
    *) echo "invalid option" ;;

    esac
    echo -n "Enter your menu choice [1-4]: "
done
