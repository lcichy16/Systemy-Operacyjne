#!/bin/bash


function odwroc_napis {
    local napis="$1"
    local odwrocony=""
    
    
    for ((i=${#napis}-1; i>=0; i--)); do
        odwrocony="${odwrocony}${napis:i:1}"
    done

    echo "$odwrocony"
}


wynik=$(odwroc_napis "$1")
echo "Odwrocony napis: $wynik"
