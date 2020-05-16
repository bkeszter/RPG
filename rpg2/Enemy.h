#ifndef ENEMY_H
#define ENEMY_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <time.h>
#include "Level.h"

typedef struct Enemy {
	int xkor;
	int ykor;
}Enemy;

Enemy* CreateE(char** palya, int hossz, int szel);
void MovementE(Enemy* player, int xkor, int ykor, char** palya);
int InputE(Enemy* enemy, char** palya);
#endif