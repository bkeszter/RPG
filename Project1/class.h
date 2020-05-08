#ifndef CLASS_H
#define CLASS_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

typedef struct ClassStructure {
	char* name;
	int class;
	int health;
	int strenght;
	int charisma;
	int defense;
}ClassStructure;


ClassStructure* CreatePlayer();
void PrintStat(ClassStructure* classstruct);
void Fight(ClassStructure* player, ClassStructure* enemy);

#endif
