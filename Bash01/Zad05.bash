#!/bin/bash


if [ $# -lt 1 ]; then
    echo "Podaj przynajmniej jeden argument."
    exit 1
fi

args=("$@")

echo "Argumenty w odwrotnej kolejności:"
for ((i=${#args[@]}-1; i>=0; i--)); do
    echo "${args[i]}"
done
