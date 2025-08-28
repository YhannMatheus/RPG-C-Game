#ifndef MUSICA_H
#define MUSICA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// Enum para identificar as faixas
typedef enum {
    MUSICA_CHEFE,
    MUSICA_AMBIENTACAO,
    MUSICA_COMBATE,
    MUSICA_NENHUMA
} TipoMusica;

// Inicializa o sistema de áudio
int inicializar_audio();

// Funções para tocar cada faixa em loop
void tocar_musica_chefe();
void tocar_musica_ambientacao();
void tocar_musica_combate();

// Para a música atual
void parar_musica();

// Controla o volume (0.0 a 1.0)
void setar_volume_musica(float volume);

// Retorna a música atual tocando
TipoMusica musica_atual();

// Limpa recursos
void limpar_audio();

#endif