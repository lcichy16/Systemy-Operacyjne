#!/bin/bash


folder=$1

oblicz_rozmiar() {
    local sciezka=$1
    local rozmiar=0

    
    for element in "$sciezka"/*; do
        if [ -f "$element" ]; then
            
            rozmiar=$((rozmiar + $(stat -c %s "$element")))
        elif [ -d "$element" ]; then
            
            rozmiar=$((rozmiar + $(oblicz_rozmiar "$element")))
        fi
    done

    echo "$rozmiar"
}


rozmiar_folderu=$(oblicz_rozmiar "$folder")

echo "Całkowity rozmiar plików w folderze $folder: $rozmiar_folderu bajtów"
