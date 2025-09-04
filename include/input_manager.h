#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

// Estrutura para gerenciar entrada assíncrona
typedef struct {
    int choice;
    bool input_ready;
    bool waiting_input;
} InputManager;

// Funções do gerenciador de entrada
int inicializar_input_manager();
void finalizar_input_manager();
int aguardar_entrada_combate();
void processar_entrada_async();

#endif // INPUT_MANAGER_H
