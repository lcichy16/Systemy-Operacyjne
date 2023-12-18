#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_SIZE 256

int countWords(const char *filename) {
    char command[MAX_COMMAND_SIZE];
    snprintf(command, sizeof(command), "wc -w < %s", filename);

    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("Błąd przy otwieraniu potoku strumieniowego");
        exit(EXIT_FAILURE);
    }

    int wordCount;
    fscanf(pipe, "%d", &wordCount);

    pclose(pipe);

    return wordCount;
}

int main() {
    const char *file1_name = "plik1.txt";
    const char *file2_name = "plik2.txt";

    int wordCount1 = countWords(file1_name);
    int wordCount2 = countWords(file2_name);

    if (wordCount1 > wordCount2) {
        printf("Plik %s zawiera więcej słów niż plik %s.\n", file1_name, file2_name);
    } else if (wordCount1 < wordCount2) {
        printf("Plik %s zawiera więcej słów niż plik %s.\n", file2_name, file1_name);
    } else {
        printf("Oba pliki zawierają tę samą liczbę słów.\n");
    }

    return 0;
}
