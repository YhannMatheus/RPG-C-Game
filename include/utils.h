#include <unistd.h>
#ifndef __USECONDS_T_DEFINED
typedef unsigned int useconds_t;
#endif

int chance();
void printSlow(const char *texto, useconds_t delay);

void clearScreen();