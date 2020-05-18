#include "Enemy.h"

Enemy* CreateE(char** palya, int hossz, int szel)
{
	srand(time(0));
	Enemy* enemy = (Enemy*)calloc(1, sizeof(Enemy));
	if (!enemy) {
		printf("hibas lefoglalas");
		exit(1);
	}
	//random helyre tesz egy ellenseget
	enemy->xkor = rand() % (szel-1)+1;
	enemy->ykor = rand() % (hossz-1)+1;

	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j < hossz; ++j) {

			//ne tegye a falra az ellensegeket
			if (enemy->xkor == 0) {
				enemy->xkor += 1;
			}
			else if (enemy->xkor == szel - 1) {
				enemy->xkor -= 1;
			}
			else if (enemy->ykor == 0) {
				enemy->ykor += 1;
			}
			else if (enemy->ykor == hossz - 1) {
				enemy->ykor -= 1;
			}
			//ne a jatekosra vagy a tuskekre tegye az ellensegeket
			if (palya[enemy->xkor][enemy->ykor] == '@' || palya[enemy->xkor][enemy->ykor] == '3') {
				enemy->xkor += 1;
				enemy->ykor += 1;
			}
			//ne az egerlyukra tegye az ellensegeket
			else if (palya[enemy->xkor][enemy->ykor] == '4') {
				enemy->ykor -= 1;
			}
			palya[enemy->xkor][enemy->ykor] = '&';
		}
	}
	
	return enemy;
}

void MovementE(Enemy* enemy, int xkor, int ykor, char** palya)
{
	//csak ures helyre lephet
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