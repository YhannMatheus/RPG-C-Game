#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "inimigo.h"
#include "player.h"
#include "utils.h"

void enemyAttack(Inimigo *inimigo, Player *jogador) {
    if (chance() < 50) {
        if(jogador -> inDefence1 == true){
            printf("\n%s atacou! mas o jogador se defendeu\n", inimigo->nome);
            jogador->inDefence1 = false;
        }
        else if(jogador -> inDefence2 == true && jogador -> inDefence1 == false){
            printf("\n%s atacou! mas o jogador se defendeu\n", inimigo->nome);
            jogador->inDefence2 = false;
        }
        else{
            printf("\n%s atacou! o jogador\n", inimigo->nome);
            jogador->hp -= inimigo->dano;
        }
    } else {
        printf("\n%s errou o ataque!\n", inimigo->nome);
    }
}

void enemyRegenerate(Inimigo *inimigo) {
    int heal = (rand() % 20) + 5;
    if (chance() < 50) {
        inimigo->hp += heal;
        printf("\n%s se regenerou em %d pontos de vida!\n", inimigo->nome, heal);
    } else {
        printf("\n%s tentou se regenerar, mas falhou!\n", inimigo->nome);
    }
}

void enemyStunnedCont(Inimigo* inimigo){
    if (inimigo->stuned) {
        
        inimigo->cooldownStun--;
        printf("O inimigo está atordoado por %d turnos!\n", inimigo->cooldownStun);
        
        if (inimigo->cooldownStun == 0) {
            inimigo->stuned = false;
            printf("O inimigo se recuperou do stun!\n");
        }
    }
}

Inimigo* generateEnemy(char nome[50]){
    Inimigo *inimigo = malloc(sizeof(Inimigo));
    
    strncpy(inimigo->nome, nome, 50);
    inimigo -> hp = 100;
    inimigo -> dano = rand() % 20;
    return inimigo;
}

void sortEnemyAction(Inimigo *inimigo, Player *jogador){
    srand(time(NULL));
    
    int action = rand() % 3;
    
    switch(action) {
        case 0:
            enemyAttack(inimigo, jogador);
            break;
        case 2:
            enemyAttack(inimigo, jogador);
            break;
        case 1:
            enemyRegenerate(inimigo);
            break;
    }
}