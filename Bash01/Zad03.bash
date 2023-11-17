#!/bin/bash

sciezka=$1


if [ -e "$sciezka" ]; then
    echo "Podana ścieżka istnieje."

    if [ -f "$sciezka" ]; then
        echo "To jest plik."

        if [ -r "$sciezka" ]; then
            echo "Użytkownik ma prawo do odczytu tego pliku."
        else
            echo "Użytkownik nie ma prawa do odczytu tego pliku."
        fi

        if [ -w "$sciezka" ]; then
            echo "Użytkownik ma prawo do zapisu do tego pliku."
        else
            echo "Użytkownik nie ma prawa do zapisu do tego pliku."
        fi

        if [ -x "$sciezka" ]; then
            echo "Użytkownik ma prawo do wykonania tego pliku."
        else
            echo "Użytkownik nie ma prawa do wykonania tego pliku."
        fi

    elif [ -d "$sciezka" ]; then
        echo "To jest katalog."

        if [ -r "$sciezka" ]; then
            echo "Użytkownik ma prawo do odczytu z tego katalogu."
        else
            echo "Użytkownik nie ma prawa do odczytu z tego katalogu."
        fi

        if [ -w "$sciezka" ]; then
            echo "Użytkownik ma prawo do zapisu do tego katalogu."
        else
            echo "Użytkownik nie ma prawa do zapisu do tego katalogu."
        fi

        if [ -x "$sciezka" ]; then
            echo "Użytkownik ma prawo do wejścia do tego katalogu."
        else
            echo "Użytkownik nie ma prawa do wejścia do tego katalogu."
        fi
    else
        echo "To nie jest ani plik, ani katalog."
    fi
else
    echo "Podana ścieżka nie istnieje."
fi
