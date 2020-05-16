#include "Enemy.h"

Enemy* CreateE(char** palya, int hossz, int szel)
{
	//srand(time(0));
	Enemy* enemy = (Enemy*)calloc(1, sizeof(Enemy));
	if (!enemy) {
		printf("hibas lefoglalas");
		exit(1);
	}
	//random helyre tesz egy ellenseget
	enemy->xkor = 3;
	enemy->ykor = 3;

	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j < hossz; ++j) {
			palya[enemy->xkor][enemy->ykor] = '&';
		}
	}
	
	return enemy;
}

void MovementE(Enemy* enemy, int xkor, int ykor, char** palya)
{
	printf("palya %c", palya[enemy->xkor][enemy->ykor]);
	if (palya[xkor][ykor] == '0') {
		palya[xkor][ykor] = '&';
		palya[enemy->xkor][enemy->ykor] = '0';
		enemy->xkor = xkor;
		enemy->ykor = ykor;
	}
}

int InputE(Enemy* enemy, char** palya)
{
	srand(time(0));
	//random mozgas
	switch (rand()%4) {
		//felfele
	case 0:
		MovementE(enemy, enemy->xkor-1, enemy->ykor + 1, palya);
		break;
		//balra
	case 1:
		MovementE(enemy, enemy->xkor, enemy->ykor-1, palya);
		break;
		//le
	case 2:
		MovementE(enemy, enemy->xkor+1, enemy->ykor, palya);
		break;
		//jobbra
	case 3:
		MovementE(enemy, enemy->xkor, enemy->ykor+1, palya);
		break;

	}
	return enemy;
}