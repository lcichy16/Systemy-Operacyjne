#!bin/bash
A=$1
B=$2

lenA=${#A}
lenB=${#B}

if [ $lenB -gt $lenA ]; then
    echo "$B jest dłuższy niż $A."
elif [ $lenB -lt $lenA ]; then
    echo "$A jest dłuższy niż $B."
else
    echo "Oba napisy mają taką samą długość."
fi

exit 0