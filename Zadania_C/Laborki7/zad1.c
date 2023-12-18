#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *plik;
    int liczba, najmniejsza, najwieksza;

    
    plik = fopen("liczby.txt", "r");
    
    
    if (plik == NULL) {
        fprintf(stderr, "Błąd przy otwieraniu pliku.\n");
        return 1;
    }

    fscanf(plik, "%d", &liczba);
    najmniejsza = najwieksza = liczba;

    while (fscanf(plik, "%d", &liczba) == 1) {
        if (liczba < najmniejsza) {
            najmniejsza = liczba;
        }
        if (liczba > najwieksza) {
            najwieksza = liczba;
        }
    }

    printf("Najmniejsza liczba: %d\n", najmniejsza);
    printf("Największa liczba: %d\n", najwieksza);

    fclose(plik);

    return 0;
}
