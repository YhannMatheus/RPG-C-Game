#ifndef CHARS_H
#define CHARS_H

typedef struct{
    char name[50];
    char clas[50];
    
    int life;
    int currentLife;
    int str;
    int dex;
    int mana;
    
    int freeStatusPoints;
    int exp;
    int xp4Level;
    int level;

    Inventory* inventory;
} Sheet;

typedef struct{
    char name[50];
    char description[100];
    char type[15];
    
    bool inUse;
    
    int power;
    int defence;
    int durability;
} Item;


typedef struct 
{
    Item* slots[10];
} Inventory;


void attack(Sheet* attacker, Sheet* defender);

Sheet* createCharacter();

bool isDead(Sheet* character);

void levelUp(Sheet* character);

Item* analyzeItem(Item* item);

Item* createItem();

void useItem(Sheet* character, Item* item);

void openInventory(Sheet* character);

#endif