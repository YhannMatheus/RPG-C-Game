#ifndef INIMIGO_H
#define INIMIGO_H

#include <stdbool.h>
#include "player.h"

typedef struct Inimigo {
    char nome[50];
    int hp;
    int dano;

    bool stuned;
    int cooldownStun;
} Inimigo;

void enemyAttack(Inimigo *inimigo, Player *jogador);

void enemyRegenerate(Inimigo *inimigo);

Inimigo* generateEnemy(char nome[50]);

void sortEnemyAction(Inimigo *inimigo, Player *jogador);

void enemyStunendCont(Inimigo* inimigo);

#endif // INIMIGO_H