#include "Level.h"
#include "Player.h"
#include "Enemy.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <Windows.h>

int main() {

	char** palya = beolvas("Text.txt",16,8);
	Print(palya, 16, 8);

	Player* player = CreateP(palya, 16, 8);
	Enemy* enemy = CreateE(palya, 16, 8);

	time_t current, start;
	start = time(NULL);
	int ch;
	while (1) {
		
		if (ch = getch() == 'q') {
			break;
		}
		current = time(NULL);

		Input(ch, player, palya);
		MovementE(enemy, palya);

		if (current - start > 10) {
			printf("Lejart az ido!");
			break;
		}
	}
	return 0;
}