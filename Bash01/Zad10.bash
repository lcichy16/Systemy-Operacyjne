#!/bin/bash



suma=0
for arg in "$@"; do
    suma=$((suma + arg))
done


srednia=$(( (suma + $# / 2) / $# ))


echo "Średnia zaokrąglona do części całkowitej: $srednia"
