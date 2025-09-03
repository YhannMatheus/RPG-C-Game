#include "musica.h"

// Array de ponteiros para músicas
static Mix_Music *musicas[3] = {NULL, NULL, NULL}; // MUSICA_CHEFE=0, MUSICA_AMBIENTACAO=1, MUSICA_COMBATE=2
static TipoMusica musica_atual_tocando = MUSICA_NENHUMA;

int inicializar_audio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) return 0;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) return 0;
    // Carrega músicas
    musicas[MUSICA_CHEFE] = Mix_LoadMUS("./sounds/Chefe.mp3");
    musicas[MUSICA_AMBIENTACAO] = Mix_LoadMUS("./sounds/Ambientação.mp3");
    musicas[MUSICA_COMBATE] = Mix_LoadMUS("./sounds/Combate.mp3");
    Mix_VolumeMusic(64);
    return 1;
}

void tocar_musica(TipoMusica tipo) {
    if (tipo == musica_atual_tocando && Mix_PlayingMusic()) return; // já está tocando
    if (!musicas[tipo]) return;
    
    // Para música atual com uma pequena pausa para evitar conflitos
    if (Mix_PlayingMusic()) {
        Mix_HaltMusic();
        SDL_Delay(50); // pausa de 50ms para estabilizar
    }
    musica_atual_tocando = MUSICA_NENHUMA;
    
    if (Mix_PlayMusic(musicas[tipo], -1) == 0) {
        musica_atual_tocando = tipo;
    }
}

void parar_musica() {
    if (Mix_PlayingMusic()) {
        Mix_HaltMusic();
        musica_atual_tocando = MUSICA_NENHUMA;
    }
}

void setar_volume_musica(float volume) {
    int volume_int = (int)(volume * 128);
    if (volume_int < 0) volume_int = 0;
    if (volume_int > 128) volume_int = 128;
    Mix_VolumeMusic(volume_int);
}

TipoMusica musica_atual() {
    return musica_atual_tocando;
}

void limpar_audio() {
    parar_musica();
    for (int i = 0; i < 3; i++) {
        if (musicas[i]) {
            Mix_FreeMusic(musicas[i]);
            musicas[i] = NULL;
        }
    }
    Mix_CloseAudio();
    SDL_Quit();
}