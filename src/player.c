#include <stdbool.h>
#include <stdio.h>
#include "player.h"
#include "inimigo.h"
#include <stdlib.h>


void attack(Player *jogador, Inimigo *inimigo) {
    
    if (inimigo-> hp <= 0) {
        printf("\n%s foi derrotado!\n", inimigo->nome);
    }

    if(rand() % 100 < jogador -> chanceOfHit){
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

void useLight(Player* jogador, Inimigo* inimigo) {
    inimigo -> stuned = true;
    jogador -> lightCooldown = 3;
}

void cooldownLight(Player* jogador) {
    if (jogador->lightCooldown > 0) {
        jogador->lightCooldown--;
    }
}

bool isPlayerAlive(Player *jogador) {
    return jogador->hp > 0;
}

void heal(Player *jogador){
    if(jogador -> hp > 0){
        jogador -> hp += 10;
        printf("\nO jogador se cura em 10 pontos de vida!\n");
    }
    if(jogador -> hp > jogador -> maxHp){
        jogador -> hp = jogador -> maxHp;
    }
}

Player inicializarJogador() {
    Player jogador;
    jogador.hp = 100;
    jogador.maxHp = 100;
    jogador.dano = 20;
    jogador.chanceOfHit = 75;
    jogador.inDefence1 = false;
    jogador.inDefence2 = false;
    jogador.potionReleased = false;
    jogador.potionQuantity = 3;
    jogador.lightReleased = false;
    jogador.lightCooldown = 0;
    return jogador;
}
