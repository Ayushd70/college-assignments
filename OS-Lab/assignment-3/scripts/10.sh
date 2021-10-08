#!/bin/bash

i="y"
echo "Enter name of the file "
read -r file
if [[ ! -e $file ]]; then
    touch "$file"
    echo "ROLL NUMBER  |  NAME  |  CITY" >>"$file"

fi

while [ $i = "y" ]; do
    echo "1.View the Data Base "
    echo "2.View Specific Records "
    echo "3.Add Records "
    echo "4.Delete Records "
    echo "5.Update Records "
    echo "6.Exit "
    echo "Enter your choice "
    read -r ch
    case $ch in
    1) sort -k 1 "$file" ;;
    2)
        echo "Enter Roll Number"
        read -r id
        grep -i "$id" "$file"
        ;;
    3)
        echo "Enter Roll Number: "
        read -r id
        echo "Enter new Student name: "
        read -r name
        echo "Enter City: "
        read -r city
        echo "$id  |  $name  |  $city" >>"$file"
        ;;
    4)
        echo "Enter Roll Number"
        read -r id
        dbs1=$(grep -v "$id" "$file")
        echo "$dbs1" >"$file"
        echo "Record is deleted"
        cat "$file"
        ;;
    5)
        echo "Enter Roll No of the student to update"
        read -r id
        dbs1=$(grep -v "$id" "$file")
        echo "$dbs1" >"$file"
        echo "Enter new Student name: "
        read -r name
        echo "Enter City: "
        read -r city
        echo "$id  |  $name  |  $city" >>"$file"
        ;;
    6) exit ;;
    *) echo "Invalid choice " ;;
    esac
    echo "Press y to continue, press any other key to exit!"
    read -r i
    if [ "$i" != "y" ]; then
        exit
    fi
done
