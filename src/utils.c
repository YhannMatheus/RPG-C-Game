#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "utils.h"


int chance() {
    srand((unsigned int)time(NULL));
    return rand() % 101;
}

void printSlow(const char *texto, useconds_t delay) {
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        fflush(stdout);
        usleep(delay * 10000); // delay em microssegundos (100000 = 0.1s)
    }
    putchar('\n');
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}