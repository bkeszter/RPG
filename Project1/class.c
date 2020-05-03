#include "class.h"



ClassStructure* CreatePlayer()
{
	ClassStructure* cs = (ClassStructure*)calloc(1, sizeof(ClassStructure));
	if (!cs) {
		printf("hibas lefoglalas");
	}
	cs->name = (char*)calloc(30, sizeof(char));
	printf("\nMi a karaktered neve? \n", cs->name);
	scanf("%[^\n]%*c", cs->name);
	printf("valassz osztalyt:\n0-HARCOS\n1-VARAZSLO\n2-DALNOK\n%i",cs->class);
	scanf("%i", &cs->class);
	if (cs->class == 0) {
		printf("A HARCOS osztalyt valsztottad");
		cs->health = 50;
		cs->strenght = 6;
		cs->charisma = 2;
		cs->defense = 5;
	}else if (cs->class == 1) {
		printf("A VARAZSLO osztalyt valasztottad");
		cs->health = 20;
		cs->strenght = 4;
		cs->charisma = 4;
		cs->defense = 2;
	}else if (cs->class == 2) {
		printf("A DALNOK osztalyt valasztottad");
		cs->health = 35;
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

int Fight(ClassStructure* player, ClassStructure* enemy)
{
	int attack = player->strenght - enemy->defense;
	int choice;
	scanf("%i", choice);
	switch (choice) {
	case 1:
		enemy->health -= attack;
		printf("%i ereju utest mertel ellenfeledre", attack);
		PrintStat(enemy);
		break;
	case 2:
		printf("megprobalod kibeszelni magad a szituaciobol");
		if (player->charisma > enemy->charisma) {
			printf("sikeresen meggyozted ellenfeled hogy szuksegtelen harcolni");
		}
		else if (player->charisma == enemy->charisma) {
			printf("nem vagy biztos benne, hogy meggyozted az ellenfeled");
		}
		else {
			printf("az ellenfeled duhbe gurult a makogasottol, nem tudtad meggyozni");
		}
		break;
	case 3:
		printf("FUTAS");
		break;
	default:
		printf("Nincs ilyen utasitas");
	}

	return attack;
}
