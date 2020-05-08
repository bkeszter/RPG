#ifndef CLASS_H
#define CLASS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

typedef struct Enemy{

	char* name;
	int health;
	int attack;
	int defense;
	int charisma;

}Enemy;

Enemy* CreateE();
Enemy* SpawnE();

#endif
