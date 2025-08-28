#include <stdlib.h>
#include <time.h>
#include "inimigo.h"
#include "player.h"
#include "utils.h"

void enemyAttack(Inimigo *inimigo, Player *jogador) {
    if (chance() < 50) {
        printf("%s atacou! o jogador\n", inimigo->nome);
        jogador->hp -= inimigo->dano;
    } else {
        printf("%s errou o ataque!\n", inimigo->nome);
    }
}

void enemyRegenerate(Inimigo *inimigo) {
    if (chance() < 30) {
        inimigo->hp += 10;
        printf("%s se regenerou em 10 pontos de vida!\n", inimigo->nome);
    } else {
        printf("%s tentou se regenerar, mas falhou!\n", inimigo->nome);
    }
}

Inimigo* generateEnemy(){
    Inimigo *inimigo = malloc(sizeof(Inimigo));
    inimigo->nome = "Inimigo Genérico";
    inimigo->hp = 100;
    inimigo->dano = rand() % 15;
    return inimigo;
}