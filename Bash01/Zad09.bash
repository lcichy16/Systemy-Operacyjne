#!/bin/bash


podslowo=$1

ilosc_plikow=$(find / -maxdepth 1 -name "*$podslowo*" -type f | wc -l)
ilosc_katalogow=$(find / -maxdepth 1 -name "*$podslowo*" -type d | wc -l)


echo "Ilość plików zawierających podsłowo '$podslowo': $ilosc_plikow"
echo "Ilość katalogów zawierających podsłowo '$podslowo': $ilosc_katalogow"
