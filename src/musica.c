#include "musica.h"
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Array de ponteiros para músicas
static Mix_Music *musicas[3] = {NULL, NULL, NULL}; // MUSICA_CHEFE=0, MUSICA_AMBIENTACAO=1, MUSICA_COMBATE=2
static TipoMusica musica_atual_tocando = MUSICA_NENHUMA;
static TipoMusica musica_solicitada = MUSICA_NENHUMA;

// Thread e semáforos
static pthread_t thread_musica;
static sem_t sem_musica_mudanca;
static sem_t sem_musica_controle;
static int thread_ativa = 0;

// Thread que gerencia a música em background
void* thread_gerenciador_musica(void* arg) {
    while (thread_ativa) {
        sem_wait(&sem_musica_mudanca); // Espera sinal para trocar música
        
        if (!thread_ativa) break;
        
        sem_wait(&sem_musica_controle); // Semáforo para controle crítico
        
        if (musica_solicitada != musica_atual_tocando) {
            // Para música atual
            if (Mix_PlayingMusic()) {
                Mix_HaltMusic();
                usleep(50000); // 50ms de pausa
            }
            
            // Toca nova música se válida
            if (musica_solicitada != MUSICA_NENHUMA && musicas[musica_solicitada]) {
                if (Mix_PlayMusic(musicas[musica_solicitada], -1) == 0) {
                    musica_atual_tocando = musica_solicitada;
                } else {
                    musica_atual_tocando = MUSICA_NENHUMA;
                }
            } else {
                musica_atual_tocando = MUSICA_NENHUMA;
            }
        }
        
        sem_post(&sem_musica_controle);
    }
    return NULL;
}

int inicializar_audio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) return 0;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) return 0;
    
    // Carrega músicas
    musicas[MUSICA_CHEFE] = Mix_LoadMUS("./sounds/Chefe.mp3");
    musicas[MUSICA_AMBIENTACAO] = Mix_LoadMUS("./sounds/Ambientação.mp3");
    musicas[MUSICA_COMBATE] = Mix_LoadMUS("./sounds/Combate.mp3");
    Mix_VolumeMusic(64);
    
    // Inicializa semáforos
    sem_init(&sem_musica_mudanca, 0, 0);
    sem_init(&sem_musica_controle, 0, 1);
    
    // Inicia thread de música
    thread_ativa = 1;
    pthread_create(&thread_musica, NULL, thread_gerenciador_musica, NULL);
    
    return 1;
}

void tocar_musica(TipoMusica tipo) {
    sem_wait(&sem_musica_controle);
    musica_solicitada = tipo;
    sem_post(&sem_musica_controle);
    sem_post(&sem_musica_mudanca); // Sinaliza thread para trocar música
}

void parar_musica() {
    sem_wait(&sem_musica_controle);
    musica_solicitada = MUSICA_NENHUMA;
    sem_post(&sem_musica_controle);
    sem_post(&sem_musica_mudanca);
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
    // Para thread de música
    thread_ativa = 0;
    sem_post(&sem_musica_mudanca); // Desperta thread para finalizar
    pthread_join(thread_musica, NULL);
    
    // Para música e libera recursos
    if (Mix_PlayingMusic()) {
        Mix_HaltMusic();
    }
    
    for (int i = 0; i < 3; i++) {
        if (musicas[i]) {
            Mix_FreeMusic(musicas[i]);
            musicas[i] = NULL;
        }
    }
    
    // Destrói semáforos
    sem_destroy(&sem_musica_mudanca);
    sem_destroy(&sem_musica_controle);
    
    Mix_CloseAudio();
    SDL_Quit();
}