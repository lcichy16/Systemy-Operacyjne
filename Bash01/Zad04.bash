#!/bin/bash

today=$(date +'%Y-%m-%d')

# Tworzymy katalog o nazwie dzisiejszej daty
mkdir "$today"

# Sprawdzamy, czy katalog został utworzony
if [ -d "$today" ]; then
    echo "Utworzono katalog $today."

    # Kopiujemy wszystkie pliki utworzone dzisiaj w katalogu domowym do nowego katalogu
    find ~/ -maxdepth 1 -type f -newermt "$today" ! -newermt "$today+1 day" -exec cp {} "$today" \;
    
    echo "Skopiowano wszystkie pliki utworzone dzisiaj do katalogu $today."
else
    echo "Nie można utworzyć katalogu $today."
fi
