#!/bin/bash
# Instala SDL2 e SDL2_mixer no Linux (Ubuntu/Debian)

echo "Instalando dependências do projeto..."

sudo apt-get update
sudo apt-get install -y libsdl2-dev libsdl2-mixer-dev

echo "Dependências instaladas!"
