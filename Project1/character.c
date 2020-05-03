#include "character.h"

Charachter* Create()
{
	Charachter* chara = (Charachter*)calloc(1, sizeof(Charachter));
	if (!chara) {
		printf("hibas lefoglalas");
	}
	chara->name = (char*)calloc(30, sizeof(char));
	printf("Mi a karaktered neve? \n",chara->name);
	scanf("%[^\n]%*c", chara->name);
	chara->health = 10;
	return chara;
}

void PrintStats(Charachter* charachter)
{
	printf("A karaktered adatai:\n");
	printf("A karaktered neve: %s", charachter->name);
	printf("\nA karaktered HP-ja: %i", charachter->health);
}

void Destroy(Charachter* charachter)
{
	free(charachter->name);
	charachter->health = 0;
	free(charachter);
}
