#include "class.h"

ClassStructure* CreatePlayer()
{
	ClassStructure* cs = (ClassStructure*)calloc(1, sizeof(ClassStructure));
	if (!cs) {
		printf("hibas lefoglalas");
		exit(1);
	}
	cs->name = (char*)calloc(30, sizeof(char));
	if (!cs->name) {
		printf("hibas lefoglalas");
		exit(1);
	}
	printf("\nMi a karaktered neve? \n", cs->name);
	scanf("%[^\n]%*c", cs->name);
	printf("\n");
	printf("valassz osztalyt:\n0-HARCOS\n1-VARAZSLO\n2-DALNOK\n%i",cs->class);
	scanf("%i", &cs->class);
	if (cs->class == 0) {
		printf("A HARCOS osztalyt valsztottad\n");
		cs->health = 20;
		cs->strenght = 7;
		cs->charisma = 2;
		cs->defense = 5;
	}
	if (cs->class == 1) {
		printf("A VARAZSLO osztalyt valasztottad\n");
		cs->health = 10;
		cs->strenght = 5;
		cs->charisma = 4;
		cs->defense = 2;
	}
	if (cs->class == 2) {
		printf("A DALNOK osztalyt valasztottad\n");
		cs->health = 15;
		cs->strenght = 2;
		cs->charisma = 7;
		cs->defense = 4;
	}
	return cs;
}

void PrintStat(ClassStructure* classstrukt)
{
	printf("\nA karaktered adatai:\n");
	printf("A karaktered neve: %s", classstrukt->name);
	printf("\nA karaktered osztalya: %i ", classstrukt->class);
	printf("\nA karaktered HP-ja: %i", classstrukt->health);
	printf("\nA karaktered ereje: %i", classstrukt->strenght);
	printf("\nA karaktered karizmaja: %i", classstrukt->charisma);
	printf("\nA karaktered vedelme: %i", classstrukt->defense);
}

void Fight(ClassStructure* player, ClassStructure* enemy)
{
	int attack = player->strenght - enemy->defense;
	int choice;
	printf("Mit szeretnel csinalni?\n1-tamadas\n2-beszed\n0-menekules\n");
	scanf("%i", &choice);
	while (choice !=0 ) {
		switch (choice) {
		case 0:
			printf("FUTAS!!");
			break;
		case 1:
			enemy->health -= attack;
			printf("%i ereju utest mertel ellenfeledre", attack);
			PrintStat(enemy);
			break;
		case 2:
			printf("megprobalod kibeszelni magad a szituaciobol...\n");
			if (player->charisma > enemy->charisma) {
				printf("sikeresen meggyozted ellenfeled hogy szuksegtelen harcolni\n");
				printf("Megnovekedett a karizmad!");
				player->charisma ++;
				break;
			}
			else if (player->charisma == enemy->charisma) {
				printf("nem vagy biztos benne, hogy meggyozted az ellenfeled\n");
				break;
			}
			else {
				printf("nem tudtad meggyozni\n");
				break;
			}
			break;
		default:
			printf("Nincs ilyen utasitas");
		}
		printf("Mit szeretnel csinalni?\n1-tamadas\n2-beszed\n0-menekules\n");
		scanf("%i", &choice);	
	}
	while (enemy->health != 0) {
		Fight(player,enemy);
		if (enemy->health <= 0) {
			printf("gyoztel");
			break;
		}
		else {
			ClassStructure* temp = player;
			player = enemy;
			enemy = temp;
		}
		
	}
	if (player->health <= 0) {
		printf("GAME OVER");
	}
}
