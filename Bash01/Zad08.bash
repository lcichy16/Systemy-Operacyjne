#!/bin/bash


login=$1

if id "$login" &>/dev/null; then
    terminal_path=$(getent passwd "$login" | cut -d: -f7)
    
    if [ -n "$terminal_path" ]; then
        echo "Ścieżka do terminala użytkownika $login: $terminal_path"
    else
        echo "Nie można znaleźć ścieżki do terminala dla użytkownika $login."
    fi
else
    echo "Użytkownik o loginie $login nie istnieje."
fi
