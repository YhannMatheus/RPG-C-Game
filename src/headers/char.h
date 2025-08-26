#ifndef CHARS_H
#define CHARS_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
    char name[50];
    char description[100];
    char type[15];
    bool inUse;
    int power;
    int defence;
    int durability;
} Item;

typedef struct {
    Item* slots[10];
} Inventory;

typedef struct {
    char name[50];
    char clas[50];
    char type[10];

    int life;
    int currentLife;
    
    int str;
    int pow;
    int dex;
    int def;
    int mana;
    
    int freeStatusPoints;
    int exp;
    int xp4Level;
    int level;
    Inventory* inventory;

} Sheet;

void clear();

Sheet* createChar();

void printCharacter(Sheet character);

bool isDead(Sheet* character);

void attack(Sheet* attacker, Sheet* defender);

void heal(Sheet* character, int quantity);

void levelUp(Sheet* character);

void openInventory(Sheet* character);

Sheet* createCharacter();

Item* analyzeItem(Item* item);

Item* createItem();

void useItem(Sheet* character, Item* item);

#endif