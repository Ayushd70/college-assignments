#!/bin/bash

trap "exit" INT TERM ERR
trap "kill 0" EXIT

./someProcessA &
./someProcessB &

wait
