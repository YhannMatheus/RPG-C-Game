// src/main.c
#include <ncurses.h>

int main() {
    initscr();
    noecho();
    curs_set(0);

    mvprintw(10, 20, "Tudo funcionando no WSL! Pressione qualquer tecla.");
    refresh();

    getch();

    endwin();
    return 0;
}

