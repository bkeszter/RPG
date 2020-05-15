#include "Level.h"
#include "Player.h"
#include "Enemy.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

int main() {

	char** palya = beolvas("Text.txt",16,8);
	Player* player = CreateP(palya, 16,8);
	Print(palya, 16, 8);
	
	char** palya2 = beolvas("Text2.txt", 24, 12);
	Print(palya2, 24, 12);

	char** palya3 = beolvas("Text3.txt", 30, 15);
	Print(palya3, 30, 15);

	Enemy* enemy = CreateE(palya, 16, 8);

	int ch;
	while (ch = getch() != 'q') {
			Input(ch, player, palya);
			MovementE(enemy, palya);
	}


	return 0;
}