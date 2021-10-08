#!/bin/bash

while :; do
    clear
    echo "Select the task to perform"
    echo "1. Number of presently active users"
    echo "2. Displaying some desired number of lines from top of a file."
    echo "3. Updating the access time of a given file to current time."
    echo "4. Exit"
    echo -n "Please enter option [1 - 4]"
    read -r opt
    case $opt in
    1)
        echo "List of users currently logged"
        who | more
        ;;
    2)
        echo "Enter the file name"
        read -r file
        echo "Enter the number of lines to display"
        read -r num
        echo "Displaying the top $num lines from $file"
        head -n "$num" "$file"
        ;;
    3)
        echo "Enter the file name"
        read -r file
        echo "Updating the access time of $file to current time"
        touch -a "$file"
        ;;
    4)
        echo "Exiting the script"
        echo "Quiting ..."
        exit
        ;;
    # Default Pattern
    *) echo "invalid option" ;;
    esac
done
