#!/bin/bash


folder=$1
uzytkownik=$(whoami)
data=$(date +'%Y%m%d')
archiwum="backup_${uzytkownik}_${data}.tar"


mkdir -p ~/backups


find "$folder" -type f -name "*.txt" -print0 | tar cfz ~/backups/"$archiwum" --null -T -

echo "Archiwum $archiwum zostało utworzone w folderze ~/backups."
