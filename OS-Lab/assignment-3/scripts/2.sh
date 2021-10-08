#!/bin/bash

echo -e 'Enter a word: \n> '
read -r word

if [ $(echo "$word" | rev) = "$word" ]; then
    echo "The word you entered is a palindrome"
else
    echo "The word you entered is not a palindrome"
fi
