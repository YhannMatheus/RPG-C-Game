#ifndef PLAYER_H
#define PLAYER_H

#include "iten.h"
#include <stdbool.h>

typedef struct inventory
{
    Item items[10];
    int itemCount;
} Inventory;

typedef struct {
    char name[50];

    int currentHealth;
    int maxHealth;

    int freePoints;
    int dexterity;
    int attack;
    int defense;
    
    int level;
    int currentXp;
    int exp4level;

    Inventory invetory;
} Player;

Player* createPlayer();
bool isAlive(Player* player);

#endif