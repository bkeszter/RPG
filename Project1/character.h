#ifndef CHARACTER_H
#define CHARACHTER_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

typedef struct Character {
	char* name;
	int health;
} Charachter;

Charachter* Create();
void PrintStats(Charachter* charachter);
void Destroy(Charachter* charachter);

#endif
