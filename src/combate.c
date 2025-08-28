#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "inimigo.h"

void combatMenu(Inimigo *inimigo, Player *jogador) {
    printf("Combate contra %s!\n", inimigo->nome);
    printf("Vida do inimigo: %d\n", inimigo->hp);
    
    printf("\n\n\n\n\n");
    
    printf("Vida do jogador: %d\n", jogador->hp);
    printf("Escolha uma ação:\n");
    printf("1 - Atacar\n");
    printf("2 - Defender\n");
    printf("3 - Usar item\n");
    printf("4 - Fugir\n");
}

void combate(Player *jogador, Inimigo *inimigo) {
    printf("Iniciando combate contra %s...\n", inimigo->nome);
    while (jogador->hp > 0 && inimigo->hp > 0) {
        
        combatMenu(inimigo, jogador);
        
        int choice;
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                attack(jogador, inimigo);
                break;
            case 2:
                defense(jogador);
                break;
            case 3:
                printf("Uso de itens ainda não implementado.\n");
                break;
            case 4:
                printf("Você fugiu do combate!\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }


        if (inimigo->hp > 0) {  
            sortEnemyAction(inimigo, jogador);
        
        } else {
            printf("Você derrotou %s!\n", inimigo->nome);
            free(inimigo);
            return;
        }
    }
    
}