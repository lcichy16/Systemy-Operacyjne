#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    const char *home_dir = getenv("HOME");

    if (home_dir == NULL) {
        fprintf(stderr, "Błąd: Nie można uzyskać dostępu do katalogu domowego.\n");
        return 1;
    }

    char command[MAX_BUFFER_SIZE];
    snprintf(command, sizeof(command), "ls %s", home_dir);

    FILE *ls_output = popen(command, "r");
    if (ls_output == NULL) {
        fprintf(stderr, "Błąd: Nie można uruchomić polecenia 'ls'.\n");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    char *longest_name = NULL;
    char *shortest_name = NULL;

    while (fgets(buffer, sizeof(buffer), ls_output) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; 

        printf("%s\n", buffer);

        if (longest_name == NULL || strlen(buffer) > (longest_name != NULL ? strlen(longest_name) : 0)) {
            free(longest_name);
            longest_name = strdup(buffer);
        }

        if (shortest_name == NULL || strlen(buffer) < (shortest_name != NULL ? strlen(shortest_name) : 0)) {
            free(shortest_name); 
            shortest_name = strdup(buffer);
        }
    }

    pclose(ls_output);

    if (longest_name != NULL) {
        printf("Najdłuższa nazwa: %s\n", longest_name);
        free(longest_name);
    }

    if (shortest_name != NULL) {
        printf("Najkrótsza nazwa: %s\n", shortest_name);
        free(shortest_name);
    }

    return 0;
}
