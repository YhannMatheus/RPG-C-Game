#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "char.h"
#include "utils.h"


Sheet* createChar(){
    clear();
    Sheet* character = (Sheet*) malloc(sizeof(Sheet));
    Inventory* inventory = (Inventory*) malloc(sizeof(Inventory));
    
    strcpy(character -> type, "Player");
    
    if (character == NULL || inventory == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(1);
    }

    character->inventory = inventory;

    printf("Digite o nome do personagem: ");
    scanf("%s", character -> name);

    clear();
    int op;
    printf("Escolha a classe do personagem\n\n");

    printf("Escolha sua classe\n");
    printf("1. Guerreiro\n");
    printf("2. Mago\n");
    printf("3. Arqueiro\n");
    printf("Digite o número da classe desejada: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            strcpy(character -> clas, "GUERREIRO");
            character -> life = 100;
            character -> str = 15;
            character -> pow = 0;
            character -> def = 13;
            character -> dex = 10;
            character -> mana = 5;
            break;
        case 2:
            strcpy(character -> clas, "MAGO");
            character -> life = 80;
            character -> str = 5;
            character -> pow = 15;
            character -> def = 5;
            character -> dex = 10;
            character -> mana = 15;
            break;
        case 3:
            strcpy(character -> clas, "ARQUEIRO");
            character -> life = 90;
            character -> str = 10;
            character -> pow = 5;
            character -> dex = 15;
            character -> def = 10;
            character -> mana = 10;
            break;
        default:
            fprintf(stderr, "Classe inválida\n");
            free(character);
            exit(1);
    }
    clear();
    
    printf("Personagem criado com sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();

    return character;
}


void printCharacter(Sheet character){
    clear();
    printf("___ Informações do Personagem ___\n");
    printf("Nome: %s   |   Classe: %s   |   Nível: %d\n", character.name, character.clas, character.level);
    printf("Vida: %d\n", character.life);
    printf("Força: %d  | Destreza: %d  | Poder: %d\nDefesa: %d  | Mana: %d\n", character.str, character.dex, character.pow, character.def, character.mana);
    printf("_____________________________\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

bool isDead(Sheet* character) {
    if(character -> life <= 0){
    
        for(int i = 0; i < 10; i++){
            free(character -> inventory -> slots[i]);
        }
    
        free(character -> inventory);
        free(character);
        return true;
    }

    return false;
}


void attack(Sheet* attacker, Sheet* defender) {
    if (isDead(attacker) || isDead(defender)) {
        fprintf(stderr, "Não é possível atacar: um dos personagens está morto\n");
        return;
    }

    int dano = attacker->str - (defender -> def);
    if (dano < 0) dano = 0;

    defender->life -= dano;
    printf("%s ataca %s causando %d de dano\n", attacker->name, defender->name, dano);
}

void heal(Sheet* character, int quantity){
    if (character == NULL) {
        fprintf(stderr, "Personagem inválido\n");
        return;
    }

    character -> currentLife += quantity;
    if (character -> currentLife > character -> life) {
        character -> currentLife = character -> life;
    }

    printf("%s curado em %d pontos\n", character -> name, quantity);
}

void levelUp(Sheet* character) {
    if (character -> exp >= character -> xp4Level) {
        character -> level++;
        character -> freeStatusPoints += 2;
        character -> xp4Level += 100 * character -> level;
        printf("%s subiu para o nível %d!\n", character -> name, character -> level);
    }
}

void openInventory(Sheet* character) {
    if (character == NULL || character->inventory == NULL) {
        fprintf(stderr, "Personagem ou inventário inválido\n");
        return;
    }

    printf("Inventário de %s:\n", character->name);
    for (int i = 0; i < 10; i++) {
        Item* item = character -> inventory -> slots[i];
        if (item != NULL) {
            printf("Slot %d: %s |Poder: %d  |Durabilidade: %d   |Tipo: %s\n", i, item->name, item->power, item->durability, item->type);
            printf("            |Descrição: %s\n", item->description);
        }
    }
}

void upperStatus(Sheet* character) {
    if (character == NULL) {
        fprintf(stderr, "Personagem inválido\n");
        return;
    }

    if (character -> freeStatusPoints = 0){
        printf("Você não tem pontos de status disponíveis para aumentar.\n");
        return;
    }

    int op;

    printf("___ Selecione a Habilidade que quer evoluir ____\n");
    printf("1 - Força\n");
    printf("2 - Destreza\n");
    printf("3 - Poder\n");
    printf("4 - Defesa\n");
    printf("5 - Mana\n");
    printf("Selecione uma opção: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            character->str += 1;
            break;
        case 2:
            character->dex += 1;
            break;
        case 3:
            character->pow += 1;
            break;
        case 4:
            character->def += 1;
            break;
        case 5:
            character->mana += 1;
            break;
        default:
            printf("Opção inválida\n");
            return;
    }

    character->freeStatusPoints -= 1;
    printf("Status de %s elevado com sucesso!\n", character -> name);
}

Sheet createEnemy(){
    Sheet enemy;
    Inventory inventory[2];

    strcpy(enemy.name, "Inimigo");
    strcpy(enemy.clas, "Guerreiro");
    strcpy(enemy.type, "Inimigo");
    
    enemy.life = 100;
    enemy.currentLife = 100;
    enemy.level = rand() % 5;
    enemy.str = rand() % 3 * enemy.level;
    enemy.dex = rand() % 3 * enemy.level;
    enemy.pow = rand() % 3 * enemy.level;
    enemy.def = rand() % 3 * enemy.level;
    enemy.mana = rand() % 3 * enemy.level;
    enemy.freeStatusPoints = 0;
    enemy.exp = 20;
    enemy.xp4Level = 100;
    enemy.inventory = inventory;
    
    return enemy;
}

