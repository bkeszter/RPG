#include "Level.h"

char** beolvas(const char* filename,int hossz, int szel)
{
	//srand(time(0));
	FILE* fin = fopen(filename, "r");
	if (!fin) {
		printf("hibas fajl megnyitas");
		exit(1);
	}
	char** palya = (char**)calloc(szel, sizeof(char*));
	if (!palya) {
		printf("hibas lefoglalas");
	}
	for (int i = 0; i < szel; ++i) {
		palya[i] = (char*)calloc(hossz, sizeof(char));
		if (!palya[i]) {
			printf("hibas lefoglalas");
		}
	}
	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j <hossz; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
			//palya[i][j] = rand() % 5;
		}
	}
	return palya;
}

void Print(char** palya, int hossz, int szel)
{
	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j < hossz; ++j) {
			//keret
			if (i == 0 || i == szel - 1) {
				printf("-");
			}
			else if (j == 0 || j == hossz - 1) {
				printf("|");
			}

			//ha 3-at lat irjon ki 'x'-et, ha 2-t 'p'-t stb...
			if (palya[i][j] == '3') {
				printf("x");
			}
			else if (palya[i][j] == '2') {
				printf("P");
			}
			else if (palya[i][j] == '4') {
				printf("O");
			}
			else if (palya[i][j] == '0') {
				printf(" ");
			}
		}
		printf("\n");
	}
}
