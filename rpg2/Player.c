#include "Player.h"

Player* CreateP(char** palya,int hossz, int szel)
{
	Player* player = (Player*)calloc(1, sizeof(Player));
	if (!player) {
		printf("hibas lefoglalas");
		exit(1);
	}
	player->health = 3;
	player->xkor = 1;
	player->ykor = 1;
	palya = beolvas("Text.txt",hossz,szel);
	//ezen a koordinatan inditja a 'player'-t
	palya[player->xkor][player->ykor]='@';	
	return player;
}

int Movement(Player* player, int xkor, int ykor, char** palya)
{
	palya = beolvas("Text.txt", 16, 8);
	 xkor = player->xkor;
	 ykor = player->ykor;
	 if (palya[player->xkor][player->ykor] == '0') {
		 palya[player->xkor][player->ykor] == '@';
		 palya[xkor][ykor] == '0';
	 }
	return player;
}

int Input(int input, Player* player,char** palya)
{
	palya = beolvas("Text.txt", 16, 8);
	switch (input) {
	//felfele
		input = getch();
	case 1:
		if (input == 'w'|| input=='W') {
			Movement(player, player->xkor, player->ykor + 1,palya);
		}
		break;
	//balra
	case 2:
		if (input == 'a'||input=='A') {
			Movement(player, player->xkor - 1, player->ykor,palya);
		}
		break;
	//le
	case 3:
		if (input == 's'||input=='S') {
			Movement(player, player->xkor, player->ykor - 1,palya);
		}
		break;
	//jobbra
	case 4:
		if (input == 'd'|| input=='D') {
			Movement(player, player->xkor + 1, player->ykor,palya);
		}
		break;
	
	}
	return input;
}
