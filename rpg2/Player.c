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
	palya[player->xkor][player->ykor] = "O";
	/*for (int i = 1; i < szel; ++i) {
		for (int j = 1; j < hossz; ++j) {
			palya[i][j] = palya[player->xkor][player->ykor];
			palya[player->xkor][player->ykor] = "P";
			printf("%c", player);
			break;
		}
	}*/

	return player;
}
