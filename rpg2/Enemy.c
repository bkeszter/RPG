#include "Enemy.h"

Enemy* CreateE(char** palya, int hossz, int szel)
{
	srand(time(0));
	palya = beolvas("Text.txt", szel, hossz);
	Enemy* enemy = (Enemy*)calloc(1, sizeof(Enemy));
	if (!enemy) {
		printf("hibas lefoglalas");
		exit(1);
	}
	enemy->xkor = rand() % (szel - hossz + 1) + hossz;
	enemy->ykor = rand() % (szel - hossz + 1) + hossz;
	//palya[enemy->xkor][enemy->ykor] = '&';
	
	return enemy;
}

int MovementE(Enemy* enemy, char** palya)
{
	srand(time(0));
	switch (rand()%4) {
		//felfele
	case 0:
		Movement(enemy, enemy->xkor, enemy->ykor + 1, palya);
		break;
		//balra
	case 1:
		Movement(enemy, enemy->xkor - 1, enemy->ykor, palya);
		break;
		//le
	case 2:
		Movement(enemy, enemy->xkor, enemy->ykor - 1, palya);
		break;
		//jobbra
	case 3:
		Movement(enemy, enemy->xkor + 1, enemy->ykor, palya);
		break;

	}
	return enemy;
}