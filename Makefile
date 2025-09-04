# Nome do seu executável final
TARGET = GAME

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g -Iinclude

# Bibliotecas a serem linkadas
LDFLAGS = -lncurses

# Diretórios
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Encontra todos os arquivos .c no diretório src
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Cria uma lista de arquivos objeto (.o) correspondentes
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Regra principal
SDL2_CHECK := $(shell pkg-config --exists sdl2 && echo OK)
SDL2_MIXER_CHECK := $(shell pkg-config --exists SDL2_mixer && echo OK)

deps:
ifeq ($(SDL2_CHECK),OK)
ifeq ($(SDL2_MIXER_CHECK),OK)
	@echo "SDL2 e SDL2_mixer já instalados."
else
	bash setup_dependencies.sh
endif
else
	bash setup_dependencies.sh
endif

SRC = src/main.c src/player.c src/inimigo.c src/combate.c src/utils.c src/musica.c src/input_manager.c
BIN = bin/rpg_game

all:
	$(CC) -Iinclude $(SRC) -o $(BIN) $(shell pkg-config --cflags --libs sdl2 SDL2_mixer) -lpthread

run: all
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean

# Regra para criar o executável final
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Executável criado em $(BIN_DIR)/$(TARGET)"

# Regra para compilar cada arquivo .c em um arquivo .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Arquivos de compilação removidos."

.PHONY: all clean
