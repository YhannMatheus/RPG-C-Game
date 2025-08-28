#include "musica.h"

// Ponteiros para as músicas
static Mix_Music *musica_chefe = NULL;
static Mix_Music *musica_ambientacao = NULL;
static Mix_Music *musica_combate = NULL;

// Música atual
static TipoMusica musica_atual_tocando = MUSICA_NENHUMA;

int inicializar_audio() {
    // Inicializa SDL áudio
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        return 0;
    }
    
    // Inicializa mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        return 0;
    }
    
    // Carrega as músicas silenciosamente
    musica_chefe = Mix_LoadMUS("Chefe.mp3");
    musica_ambientacao = Mix_LoadMUS("Ambientação.mp3");
    musica_combate = Mix_LoadMUS("Combate.mp3");
    
    // Configura volume inicial
    Mix_VolumeMusic(64);
    
    return 1;
}

void tocar_musica_chefe() {
    if (!musica_chefe) return;
    
    // Para música atual se estiver tocando
    parar_musica();
    
    // Toca a nova música em loop
    if (Mix_PlayMusic(musica_chefe, -1) == 0) {
        musica_atual_tocando = MUSICA_CHEFE;
    }
}

void tocar_musica_ambientacao() {
    if (!musica_ambientacao) return;
    
    parar_musica();
    
    if (Mix_PlayMusic(musica_ambientacao, -1) == 0) {
        musica_atual_tocando = MUSICA_AMBIENTACAO;
    }
}

void tocar_musica_combate() {
    if (!musica_combate) return;
    
    parar_musica();
    
    if (Mix_PlayMusic(musica_combate, -1) == 0) {
        musica_atual_tocando = MUSICA_COMBATE;
    }
}

void parar_musica() {
    if (Mix_PlayingMusic()) {
        Mix_HaltMusic();
        musica_atual_tocando = MUSICA_NENHUMA;
    }
}

void setar_volume_musica(float volume) {
    // Converte de 0.0-1.0 para 0-128
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
    
    // Libera as músicas da memória
    if (musica_chefe) {
        Mix_FreeMusic(musica_chefe);
        musica_chefe = NULL;
    }
    if (musica_ambientacao) {
        Mix_FreeMusic(musica_ambientacao);
        musica_ambientacao = NULL;
    }
    if (musica_combate) {
        Mix_FreeMusic(musica_combate);
        musica_combate = NULL;
    }
    
    Mix_CloseAudio();
    SDL_Quit();
}