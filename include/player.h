#include "inimigo.h"
#ifndef PLAYER_H
#define PLAYER_H


#include <stdbool.h>

typedef struct {
    int hp;
    int dano;
    bool inDefence1;
    bool inDefence2;
} Player;

typedef struct Inimigo Inimigo;

void attack(Player *jogador, Inimigo *inimigo);

void defense(Player *jogador);

bool isPlayerAlive(Player *jogador);

void heal(Player *jogador);

#endif // PLAYER_H