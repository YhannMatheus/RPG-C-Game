#!/bin/bash

# setup.sh - Script de configuração para o Meu Jogo
# Este script verifica se a biblioteca ncurses está instalada e, se não estiver,
# tenta instalá-la usando o gerenciador de pacotes apropriado.

echo "-------------------------------------"
echo " Verificando dependências para o jogo "
echo "-------------------------------------"
echo "Este script tentará instalar a biblioteca 'ncurses' necessária."
echo "Pode ser que a senha de administrador (sudo) seja solicitada."
echo ""

# Função para verificar se um comando existe
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Variáveis para o gerenciador de pacotes
PKG_MANAGER=""
PACKAGE_NAME=""

# Detecta o gerenciador de pacotes e define o nome do pacote ncurses
if command_exists apt; then
    PKG_MANAGER="apt"
    # A 'w' é de wide-character, importante para caracteres especiais
    PACKAGE_NAME="libncursesw6" 
elif command_exists dnf; then
    PKG_MANAGER="dnf"
    PACKAGE_NAME="ncurses-libs"
elif command_exists pacman; then
    PKG_MANAGER="pacman"
    PACKAGE_NAME="ncurses"
elif command_exists zypper; then
    PKG_MANAGER="zypper"
    PACKAGE_NAME="ncurses-utils" # O nome pode variar em OpenSUSE
else
    echo "AVISO: Gerenciador de pacotes não detectado (apt, dnf, pacman, zypper)."
    echo "Por favor, instale a biblioteca ncurses manualmente para o seu sistema."
    exit 1
fi

echo "Gerenciador de pacotes detectado: $PKG_MANAGER"
echo "Pacote a ser verificado: $PACKAGE_NAME"
echo ""

# Verifica se o pacote já está instalado
IS_INSTALLED=false
case "$PKG_MANAGER" in
    apt)
        # dpkg-query retorna 0 se encontrado, 1 se não
        dpkg-query -W -f='${Status}' "$PACKAGE_NAME" 2>/dev/null | grep -q "install ok installed" && IS_INSTALLED=true
        ;;
    dnf)
        # rpm -q retorna 0 se encontrado
        rpm -q "$PACKAGE_NAME" >/dev/null 2>&1 && IS_INSTALLED=true
        ;;
    pacman)
        # pacman -Q retorna 0 se encontrado
        pacman -Q "$PACKAGE_NAME" >/dev/null 2>&1 && IS_INSTALLED=true
        ;;
    zypper)
        # rpm -q retorna 0 se encontrado
        rpm -q "$PACKAGE_NAME" >/dev/null 2>&1 && IS_INSTALLED=true
        ;;
esac


if $IS_INSTALLED; then
    echo "✅ A biblioteca ncurses ($PACKAGE_NAME) já está instalada."
    echo "Tudo pronto!"
    exit 0
else
    echo "A biblioteca ncurses ($PACKAGE_NAME) não foi encontrada. Tentando instalar..."
    
    # Executa o comando de instalação apropriado com sudo
    case "$PKG_MANAGER" in
        apt)
            sudo apt update
            sudo apt install -y "$PACKAGE_NAME"
            ;;
        dnf)
            sudo dnf install -y "$PACKAGE_NAME"
            ;;
        pacman)
            # Pacman não tem uma flag -y por padrão, ele pede confirmação
            sudo pacman -S --noconfirm "$PACKAGE_NAME"
            ;;
        zypper)
            sudo zypper install -y "$PACKAGE_NAME"
            ;;
    esac

    # Verifica o resultado da instalação
    if [ $? -eq 0 ]; then
        echo "✅ Instalação concluída com sucesso!"
        echo "Tudo pronto para jogar."
    else
        echo "❌ Falha na instalação."
        echo "Por favor, tente instalar a biblioteca '$PACKAGE_NAME' manualmente."
        exit 1
    fi
fi

exit 0