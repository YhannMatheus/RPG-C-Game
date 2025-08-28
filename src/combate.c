#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "inimigo.h"
#include "utils.h"

void combatMenu(Inimigo *inimigo, Player *jogador) {
    printf("Combate contra %s!\n", inimigo->nome);
    printf("Vida do inimigo: %d\n", inimigo->hp);
    
    printf("\n\n\n\n\n");
    
    printf("Vida do jogador: %d\n", jogador->hp);
    printf("Escolha uma ação:\n");
    printf("1 - Atacar\n");
    printf("2 - Defender\n\n\n");
}

void combate(Player *jogador, Inimigo *inimigo) {
    printf("Iniciando combate contra %s...\n", inimigo->nome);
    
    printf("Pressione enter para iniciar...");
    getchar();

    while (jogador->hp > 0 && inimigo->hp > 0) {
        clearScreen();
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
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        if (inimigo->hp > 0) {  
            sortEnemyAction(inimigo, jogador);
        
        } else {
            printf("Você derrotou %s!\n", inimigo->nome);
            free(inimigo);
        }
        
        
        if (!isPlayerAlive(jogador)) {
            printf("Você foi derrotado por %s...\n", inimigo->nome);
            break;
        }

        printf("\n\nPressione enter para continuar");
        getchar();
        getchar();
    }
    
}