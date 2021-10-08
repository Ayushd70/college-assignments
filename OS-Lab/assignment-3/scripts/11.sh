#!/bin/bash

echo "Number : "
read -r n
function armstrong {
    t=$n
    s=0
    b=0
    c=10
    while [ "$n" -gt "$b" ]; do
        r=$((n % c))
        i=$((r * r * r))
        s=$((s + i))
        n=$((n / c))
    done
    if [ "$s" == "$t" ]; then
        echo "YES"
    else
        echo "NO"
    fi
}
result=$(armstrong $n)
echo "$result"
