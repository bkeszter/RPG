#include "Player.h"

Player* CreateP(char** palya, int hossz, int szel)
{
	Player* player = (Player*)calloc(1, sizeof(Player));
	if (!player) {
		printf("hibas lefoglalas");
		exit(1);
	}
	player->health = 3;
	player->points = 0;
	player->xkor = 1;
	player->ykor = 1;
	//ezen a koordinatan inditja a 'player'-t
	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j < hossz; ++j) {
			palya[player->xkor][player->ykor] = '@';
		}
	}
	
	return player;
}

void Movement(Player* player, int xkor, int ykor, char** palya)
{
	 //printf("palya %c", palya[player->xkor][player->ykor]);
	 if (palya[xkor][ykor] == '0') {
		 palya[xkor][ykor] = '@';
		 palya[player->xkor][player->ykor] = '0' ;
		 player->xkor = xkor;
		 player->ykor = ykor;
	 }
	 else if (palya[xkor][ykor] == '3' || palya[xkor][ykor]=='&') {
		 player->health -= 1;
	 }
}

int Input(int input, Player* player,char** palya)
{
	
	//mozgas WASD billentyukkel

	//input = getch();
	switch (input) {
	//felfele
		
	case 'w':
	case 'W':
		Movement(player, player->xkor-1, player->ykor,palya);
		break;
	//balra
	case 'a':
	case 'A':
		Movement(player, player->xkor, player->ykor-1, palya);
		break;
	//le
	case 's':
	case 'S':
		Movement(player, player->xkor+1, player->ykor,palya);
		break;
	//jobbra
	case 'd':
	case 'D':
		Movement(player, player->xkor , player->ykor+1,palya);
		break;
	}
	return input;
}

int Points(char** palya, Player* player,int szel, int hossz,int xkor,int ykor)
{
	Player* temp = CreateP(palya, szel, hossz);
	if (palya[xkor][ykor] == '2') {
		player->points += 1;
	}
	else if (palya[xkor][ykor] == '4') {
		temp->points += player->points;
		player->points = 0;
	}


	printf("%i", temp->points);
	return temp->points;
}
