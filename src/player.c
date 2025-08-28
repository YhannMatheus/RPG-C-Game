#include <stdbool.h>
#include <stdio.h>
#include "player.h"
#include "inimigo.h"


void attack(Player *jogador, Inimigo *inimigo) {
    
    if (inimigo->hp <= 0) {
        printf("%s foi derrotado!\n", inimigo->nome);
    }

    if(rand() % 100 > 60){
        inimigo -> hp -= jogador -> dano;
        printf("\nO jogador ataca %s e causa %d de dano!\n", inimigo -> nome, jogador -> dano);
    }else{
        printf("\nO jogador tentou atacar mas errou!\n");
    }
}

void defense(Player *jogador) {
    jogador -> inDefence1 = true;
    jogador -> inDefence2 = true;

    printf("O jogador está com a guarda alta!\n");
}

bool isPlayerAlive(Player *jogador) {
    return jogador->hp > 0;
}