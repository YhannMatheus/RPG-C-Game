#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void create_char_menu(WINDOW* win, Player* player, int point_left, int current_selection);

Player* handle_player_creator_scene(){
    Player* new_char = (Player*) malloc(sizeof(Player));
    if(new_char == NULL){
        return NULL;
    }

    strcpy(new_char->name, "<name>");
    new_char->currentHealth = 100;
    new_char->maxHealth = 100;
    new_char->invetory.itemCount = 0;
    new_char->currentXp = 0;
    new_char->exp4level= 100;
    new_char->level = 1;
    new_char->freePoints = 2;
    new_char->attack = 10;
    new_char->defense = 10;
    new_char->dexterity = 10;


    const int TOTAL_POINTS = 2
    
    return new_char;
}

