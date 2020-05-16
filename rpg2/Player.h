#ifndef PLAYER_H
#define PLAYER_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "Level.h"

typedef struct Player {
	int health;
	int xkor;
	int ykor;
}Player;

Player* CreateP(char** palya,int hossz,int szel);
void Movement(Player* player,int xkor,int ykor,char** palya);
int Input(int input, Player* player,char** palya);
#endif
