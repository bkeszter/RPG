#include "enemies.h"
#include <time.h>

Enemy* CreateE()
{
	srand(time(0));
	Enemy* enemy = (Enemy*)calloc(1, sizeof(Enemy));
	if (!enemy) {
		printf("hibas lefoglalas");
	}
	enemy->name = (char*)calloc(30,sizeof(char));
	if (!enemy->name) {
		printf("hiba");
	}
	int number;
	number = rand() % (4)+1;
	scanf("%i", number);
	switch (number)	{
		while (number != 0) {
			if (number == 1) {
				enemy->name = "Goblin";
				enemy->health = 5;
				enemy->attack = 3;
				enemy->defense = 2;
				enemy->charisma = 2;
			}
			if (number == 2) {
				enemy->name = "Rem Farkas";
				enemy->health = 7;
				enemy->attack = 4;
				enemy->defense = 3;
				enemy->charisma = 3;
			}
			if (number == 3) {
				enemy->name = "Ogre";
				enemy->health = 10;
				enemy->attack = 6;
				enemy->defense = 5;
				enemy->charisma = 4;
			}
			if (number == 4) {
				enemy->name = "Sarkany";
				enemy->health = 30;
				enemy->attack = 10;
				enemy->defense = 8;
				enemy->charisma = 9;
			}
		}	
	}
	return enemy;
}

Enemy* SpawnE()
{
	for (int i = 0; i < 4; ++i) {
		switch (i) {
		case 0:
			//goblin
		case 1:
			//farkas
		case 2:
			//ogre
		case 3:
			//sarkany
		default:
			//no enemy
		}
	}

	return NULL;
}

