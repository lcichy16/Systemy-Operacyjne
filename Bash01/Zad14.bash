#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Podaj dokładnie jedną wartość jako argument."
    exit 1
fi

export test="$1"

echo "Zmienna 'test' została utworzona i wynosi: $test"


