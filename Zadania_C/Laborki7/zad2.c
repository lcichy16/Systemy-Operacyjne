#include <stdio.h>

int main() {
    int n, i;
    printf("Podaj liczbę n: ");
    scanf("%d", &n);

    FILE *negative_file = fopen("ujemne.txt", "w");
    FILE *positive_file = fopen("dodatnie.txt", "w");

    if (negative_file == NULL || positive_file == NULL) {
        printf("Błąd podczas otwierania plików.\n");
        return 1;
    }

    for (i = 0; i < n; ++i) {
        double number;
        printf("Podaj %d. liczbę: ", i + 1);
        scanf("%lf", &number);

        if (number < 0) {
            fprintf(negative_file, "%lf\n", number);
        } else if (number > 0) {
            fprintf(positive_file, "%lf\n", number);
        } else {
            fprintf(stderr, "Liczba równa 0 nie jest dozwolona.\n");
            fclose(negative_file);
            fclose(positive_file);
            return 1;
        }
    }

    fclose(negative_file);
    fclose(positive_file);

    printf("Operacja zakończona pomyślnie. Wyniki zapisane w plikach ujemne.txt i dodatnie.txt.\n");

    return 0;
}
