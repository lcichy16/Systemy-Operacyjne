#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleSIGINT(int signal) {
    printf("Jestem nieśmiertelny! Mój PID: %d\n", getpid());
}

void handleSIGHUP(int signal) {
    printf("Przestałem reagować na SIGINT po otrzymaniu SIGHUP.\n");
    signal(SIGINT, SIG_IGN); 
}

int main() {
    signal(SIGINT, handleSIGINT);

    signal(SIGHUP, handleSIGHUP);

    while (1) {
        pause(); 
    }
    return 0;
}
