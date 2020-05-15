#include "Player.h"

Player* CreateP(char** palya, int hossz, int szel)
{
	Player* player = (Player*)calloc(1, sizeof(Player));
	if (!player) {
		printf("hibas lefoglalas");
		exit(1);
	}
	player->health = 3;
	player->xkor = 1;
	player->ykor = 1;
	palya = beolvas("Text.txt", hossz, szel);
	//ezen a koordinatan inditja a 'player'-t
	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j < hossz; ++j) {
			palya[player->xkor][player->ykor] == '@';
		}
	}
	
	return player;
}

int Movement(Player* player, int xkor, int ykor, char** palya)
{
	palya = beolvas("Text.txt", 16, 8);
	 xkor = player->xkor;
	 ykor = player->ykor;
	 if (palya[player->xkor][player->ykor] == " ") {
		 palya[player->xkor][player->ykor] == '@';
		 palya[xkor][ykor] == " ";
	 }
	return player;
}

int Input(int input, Player* player,char** palya)
{
	palya = beolvas("Text.txt", 16, 8);
	//mozgas WASD billentyukkel
	switch (input) {
	//felfele
		input = getch();
	case 'w':
	case 'W':
		Movement(player, player->xkor, player->ykor + 1,palya);
		break;
	//balra
	case 'a':
	case 'A':
		Movement(player, player->xkor - 1, player->ykor, palya);
		break;
	//le
	case 's':
	case 'S':
		Movement(player, player->xkor, player->ykor - 1,palya);
		break;
	//jobbra
	case 'd':
	case 'D':
		Movement(player, player->xkor + 1, player->ykor,palya);
		break;
	}
	return input;
}
