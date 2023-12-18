#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
} Person;

int isAlphaString(const char *str) {
    while (*str) {
        if (!isalpha((unsigned char)*str)) {
            return 0;  // Znaleziono znak niebędący literą
        }
        str++;
    }
    return 1;  // Wszystkie znaki to litery
}

int main() {
    char input_name[MAX_NAME_LENGTH];
    char input_surname[MAX_NAME_LENGTH];

    printf("Podaj imię: ");
    scanf("%s", input_name);

    printf("Podaj nazwisko: ");
    scanf("%s", input_surname);

    if (!isAlphaString(input_name) || !isAlphaString(input_surname)) {
        fprintf(stderr, "Błąd: Imię i nazwisko mogą zawierać tylko litery.\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen("baza.txt", "r");
    if (file == NULL) {
        perror("Błąd przy otwieraniu pliku baza.txt");
        return EXIT_FAILURE;
    }

    Person person;
    int found = 0;

    while (fscanf(file, "%s %s", person.name, person.surname) == 2) {
        if (strcmp(person.name, input_name) == 0 && strcmp(person.surname, input_surname) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("Osoba o imieniu %s i nazwisku %s znajduje się w pliku baza.txt.\n", input_name, input_surname);
    } else {
        printf("Nie znaleziono osoby o imieniu %s i nazwisku %s w pliku baza.txt.\n", input_name, input_surname);
    }

    return 0;
}
