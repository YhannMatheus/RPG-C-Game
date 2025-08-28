#include <stdlib.h>
#include <time.h>
#include "inimigo.h"
#include "player.h"
#include "utils.h"

void enemyAttack(Inimigo *inimigo, Player *jogador) {
    if (chance() < 50) {
        if(jogador -> inDefence1 == true){
            printf("%s atacou! mas o jogador se defendeu\n", inimigo->nome);
            jogador->inDefence1 = false;
        }
        else if(jogador -> inDefence2 == true && jogador -> inDefence1 == false){
            printf("%s atacou! mas o jogador se defendeu\n", inimigo->nome);
            jogador->inDefence2 = false;
        }
        else{
            printf("%s atacou! o jogador\n", inimigo->nome);
            jogador->hp -= inimigo->dano;
        }
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

Inimigo* generateEnemy(char nome[25]){
    Inimigo *inimigo = malloc(sizeof(Inimigo));
    strncpy(inimigo->nome, nome, 25);
    inimigo->hp = 100;
    inimigo->dano = rand() % 15;
    return inimigo;
}

void sortEnemyAction(Inimigo *inimigo, Player *jogador){
    srand(time(NULL));
    int action = rand() % 1;
    switch(action) {
        case 0:
            enemyAttack(inimigo, jogador);
            break;
        case 1:
            enemyRegenerate(inimigo);
            break;
    }
}