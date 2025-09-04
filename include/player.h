#include "inimigo.h"
#ifndef PLAYER_H
#define PLAYER_H


#include <stdbool.h>

typedef struct {
    int hp;
    int maxHp;
    int dano;

    int potionQuantity;
    bool potionReleased;

    bool lightReleased;
    int lightCooldown;

    bool inDefence1;
    bool inDefence2;

    int chanceOfHit;

} Player;

typedef struct Inimigo Inimigo;

void attack(Player *jogador, Inimigo *inimigo);

void defense(Player *jogador);

bool isPlayerAlive(Player *jogador);

void heal(Player *jogador);

void cooldownLight(Player* jogador);

void useLight(Player* jogador, Inimigo* inimigo);

Player inicializarJogador();

#endif // PLAYER_H