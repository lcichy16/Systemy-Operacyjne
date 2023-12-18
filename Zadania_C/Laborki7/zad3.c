#include <stdio.h>
#include <string.h>

int main() {
    char first_string[100], second_string[100];

    printf("Podaj pierwszy napis: ");
    fgets(first_string, sizeof(first_string), stdin);
    printf("Podaj drugi napis: ");
    fgets(second_string, sizeof(second_string), stdin);

    first_string[strcspn(first_string, "\n")] = '\0';
    second_string[strcspn(second_string, "\n")] = '\0';

    int len_first = strlen(first_string);
    int len_second = strlen(second_string);

    FILE *predzej_file = fopen("predzej.txt", "w");
    FILE *dluzszy_file = fopen("dluzszy.txt", "w");

    if (predzej_file == NULL || dluzszy_file == NULL) {
        printf("Błąd podczas otwierania plików.\n");
        return 1;
    }

    if (len_first < len_second) {
        fprintf(predzej_file, "%s\n", first_string);
        fprintf(dluzszy_file, "%s\n", second_string);
    } else if (len_first > len_second) {
        fprintf(predzej_file, "%s\n", second_string);
        fprintf(dluzszy_file, "%s\n", first_string);
    } else {
        fprintf(stderr, "Błąd: Napisy są tej samej długości.\n");
        fclose(predzej_file);
        fclose(dluzszy_file);
        return 1;
    }

    fclose(predzej_file);
    fclose(dluzszy_file);

    printf("Operacja zakończona pomyślnie. Wyniki zapisane w plikach predzej.txt i dluzszy.txt.\n");

    return 0;
}
