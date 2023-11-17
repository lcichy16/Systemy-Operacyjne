#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Brakuje argumentu. Podaj ścieżkę do pliku."
    exit 1
fi

sciezka=$1

if [ ! -e "$sciezka" ]; then
    echo "Plik nie istnieje: $sciezka"
    exit 1
fi

rozsz=${sciezka##*.}

case "$rozsz" in
    "txt")
        echo "Otwieranie pliku tekstowego: $sciezka"
        xdg-open "$sciezka"
        ;;
    "sh")
        echo "Uruchamianie skryptu: $sciezka"
        bash "$sciezka"
        ;;
    *)
        echo "Nieznane rozszerzenie pliku: $sciezka"
        ;;
esac
