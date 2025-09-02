#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "inimigo.h"
#include "utils.h"
#include "musica.h"

void combatMenu(Inimigo *inimigo, Player *jogador) {
    printf("==============================\n");
    printf("   COMBATE CONTRA %-16s\n", inimigo->nome);
    printf("==============================\n");
    printf("Vida do inimigo : %-4d\n", inimigo->hp);
    printf("Vida do jogador : %-4d\n", jogador->hp);
    printf("------------------------------\n");
    printf("Escolha uma ação:\n");
    printf("[1] Atacar\n");
    printf("[2] Defender\n");
    if (jogador->potionReleased)
        printf("[3] Usar Poção     | %2d restantes\n", jogador->potionQuantity);
    if (jogador->lightReleased)
        printf("[4] Usar Luz       | %2d turnos restantes\n", jogador->lightCooldown);
    printf("==============================\n");
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
            case 3:
                heal(jogador);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }


        if (inimigo -> hp > 0) {  
            if(inimigo -> stuned == false) { sortEnemyAction(inimigo, jogador); 
            } else { 
                enemyStunnedCont(inimigo);
                printf("O inimigo está atordoado e não pode atacar!\n");
            }

        } else {
            printf("Você derrotou %s!\n", inimigo->nome);
            free(inimigo);
        }
        
        if (!isPlayerAlive(jogador)) {
            printf("Você foi derrotado por %s...\n", inimigo->nome);
            break;
        }

        if (jogador -> lightCooldown > 0) {
            cooldownLight(jogador);
        }

        parar_musica();
        clearScreen();
        
        printf("\n\nPressione enter para continuar");
        getchar();
        getchar();
    }
    
}