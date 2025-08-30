#include <stdbool.h>
#include <stdio.h>
#include "player.h"
#include "inimigo.h"
#include <stdlib.h>


void attack(Player *jogador, Inimigo *inimigo) {
    
    if (inimigo->hp <= 0) {
        printf("\n%s foi derrotado!\n", inimigo->nome);
    }

    if(rand() % 100 > 60){
        inimigo -> hp -= jogador -> dano;
        printf("\nO jogador ataca %s e causa %d de dano!\n", inimigo -> nome, jogador -> dano);
    }else{
        printf("\nO jogador tentou atacar mas errou!\n");
    }
}

void defense(Player *jogador) {
    if(jogador -> inDefence1 == false){
        jogador -> inDefence1 = true;
        jogador -> inDefence2 = true;

        printf("\nO jogador está com a guarda alta!\n");
    }else{
        printf("\nO jogador já está com a guarda alta! Uma pessima escolha ficar somente na defensiva\n");
    }
}

bool isPlayerAlive(Player *jogador) {
    return jogador->hp > 0;
}

void heal(Player *jogador){
    if(jogador->hp > 0){
        jogador->hp += 10;
        printf("\nO jogador se cura em 10 pontos de vida!\n");
    }
    if(jogador -> hp > 100){
        jogador -> hp = 100;
    }
}
