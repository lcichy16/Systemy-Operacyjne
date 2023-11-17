#!/bin/bash

FIFO_FILE="/tmp/serwer_fifo"

if [ ! -p "$FIFO_FILE" ]; then
    echo "Serwer nie jest uruchomiony."
    exit 1
fi

read -p "Podaj napis: " napis

echo "$napis" > "$FIFO_FILE"

read -r odpowiedz < "$FIFO_FILE"

echo "$odpowiedz"