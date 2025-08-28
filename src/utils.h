#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chance() {
    srand((unsigned int)time(NULL));
    return rand() % 101;
}
