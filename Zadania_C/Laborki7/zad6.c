#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[30];
    int operation;
    char path[50];

    printf("Wpisz nazwę pliku, na którym chcesz wykonać operacje: ");
    fgets(file_name, sizeof(file_name), stdin);

    printf("Wybierz opcję 1-3:\n 1. Remove\n 2. Copy\n 3. Move\n");
    scanf("%d", &operation);

    if (operation == 1) {
        char command[100];
        snprintf(command, sizeof(command), "rm %s", file_name);
        system(command);
    } else if (operation == 2) {
        printf("Podaj ścieżkę docelową: ");
        fgets(path, sizeof(path), stdin);

        char command[100];
        snprintf(command, sizeof(command), "cp %s %s", file_name, path);
        system(command);
    } 
    
    else if (operation == 3){
        printf("Podaj ścieżkę docelową: ");
        fgets(path, sizeof(path), stdin);

        char command[100];
        snprintf(command, sizeof(command), "mv %s %s", file_name, path );
        system(command);
    }
    
    
    
    else {
        printf("Niepoprawny numer operacji.\n");
    }

    return 0;
}
