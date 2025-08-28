#ifndef INIMIGO_H
#define INIMIGO_H

#include "player.h"

typedef struct {
    char *nome[25];
    int hp;
    int dano;
} Inimigo;

void enemyAttack(Inimigo *inimigo, Player *jogador);

void enemyRegenerate(Inimigo *inimigo);

Inimigo* generateEnemy(char nome[25]);

void sortEnemyAction(Inimigo *inimigo, Player *jogador);

#endif // INIMIGO_H