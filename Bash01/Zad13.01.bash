#!/bin/bash

FIFO_FILE="/tmp/serwer_fifo"


if [ ! -p "$FIFO_FILE" ]; then
    mkfifo "$FIFO_FILE"
fi

while true; do
    
    read -r napis < "$FIFO_FILE"

    
    ilosc_samoglosek=$(echo "$napis" | tr -cd 'aeiouAEIOU' | wc -c)

    
    echo "Napis '$napis' zawiera $ilosc_samoglosek samogłosek." > "$FIFO_FILE"
done
