#ifndef INIMIGO_H
#define INIMIGO_H

#include "player.h"

typedef struct {
    char *nome;
    int hp;
    int dano;
} Inimigo;

void enemyAttack(Inimigo *inimigo, Player *jogador);

void enemyRegenerate(Inimigo *inimigo);

Inimigo* generateEnemy();

#endif // INIMIGO_H