#ifndef ITEN_H
#define ITEN_H

typedef struct{
    int attackBonus;
    int defenceBonus;
    int dexterityBonus;
    int healthBonus;

    char description[100];
} Item;

#endif