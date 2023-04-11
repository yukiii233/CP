#!/usr/bin/bash
while true; do
    ./make > data.in
    ./a < data.in > a.out
    ./b < data.in > b.out
    if diff a.out b.out; then 
        printf "Accept\n"
    else
        printf "Wrong answer\n"
        exit 0
    fi 
done
