#include <stdio.h>

int main() {
    FILE *file = fopen("przedmioty.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Błąd podczas otwierania pliku przedmioty.txt do zapisu.\n");
        return 1;
    }

    fprintf(file, "informatyka\n");
    fprintf(file, "matematyka\n");
    fprintf(file, "jezyk angielski\n");
    fclose(file);


    printf("Plik przedmioty.txt został utworzony i zaktualizowany.\n");
    return 0;
}
