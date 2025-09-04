#include "input_manager.h"
#include <stdio.h>
#include <unistd.h>

static InputManager input_mgr = {0, false, false};
static pthread_t thread_input;
static sem_t sem_input_ready;
static sem_t sem_input_request;
static int input_thread_ativa = 0;

// Thread que gerencia entrada assíncrona
void* thread_gerenciador_entrada(void* arg) {
    while (input_thread_ativa) {
        sem_wait(&sem_input_request); // Espera solicitação de entrada
        
        if (!input_thread_ativa) break;
        
        input_mgr.waiting_input = true;
        scanf("%d", &input_mgr.choice);
        getchar(); // consome \n
        
        input_mgr.input_ready = true;
        input_mgr.waiting_input = false;
        
        sem_post(&sem_input_ready); // Sinaliza que entrada está pronta
    }
    return NULL;
}

int inicializar_input_manager() {
    // Inicializa semáforos
    sem_init(&sem_input_ready, 0, 0);
    sem_init(&sem_input_request, 0, 0);
    
    // Inicia thread de entrada
    input_thread_ativa = 1;
    if (pthread_create(&thread_input, NULL, thread_gerenciador_entrada, NULL) != 0) {
        return 0;
    }
    
    return 1;
}

void finalizar_input_manager() {
    input_thread_ativa = 0;
    sem_post(&sem_input_request); // Desperta thread para finalizar
    pthread_join(thread_input, NULL);
    
    sem_destroy(&sem_input_ready);
    sem_destroy(&sem_input_request);
}

int aguardar_entrada_combate() {
    input_mgr.input_ready = false;
    sem_post(&sem_input_request); // Solicita entrada
    
    sem_wait(&sem_input_ready); // Espera entrada ficar pronta
    
    return input_mgr.choice;
}

void processar_entrada_async() {
    // Função para processar entrada de forma não-bloqueante no futuro
    // Por enquanto mantém compatibilidade com o sistema atual
}
