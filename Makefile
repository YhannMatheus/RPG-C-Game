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
all: $(BIN_DIR)/$(TARGET)

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
