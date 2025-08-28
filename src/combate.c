#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void combate(Player *jogador, char *inimigo, int hpInimigo, int danoInimigo) {
    printf("\n--- COMBATE INICIADO ---\n");
    printf("Elric enfrenta %s!\n", inimigo);

    while (jogador->hp > 0 && hpInimigo > 0) {
        printf("\nElric ataca e causa %d de dano!\n", jogador->dano);
        hpInimigo -= jogador->dano;

        if (hpInimigo <= 0) {
            printf("%s foi derrotado!\n", inimigo);
            return;
        }

        printf("%s ataca e causa %d de dano!\n", inimigo, danoInimigo);
        jogador->hp -= danoInimigo;

        if (jogador->hp <= 0) {
            printf("Elric foi derrotado... Fim da jornada.\n");
            exit(0);
        }
    }
}