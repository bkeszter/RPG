#include "Level.h"

char** beolvas(const char* filename,int hossz, int szel)
{
	//srand(time(0));
	FILE* fin = fopen(filename, "r");
	if (!fin) {
		printf("hibas fajl megnyitas");
		exit(1);
	}
	char** palya = (char**)calloc(hossz, sizeof(char*));
	if (!palya) {
		printf("hibas lefoglalas");
	}
	for (int i = 0; i < szel; ++i) {
		palya[i] = (char*)calloc(szel, sizeof(char));
		if (!palya[i]) {
			printf("hibas lefoglalas");
		}
	}
	for (int i = 0; i < szel; ++i) {
		for (int j = 0; j <hossz; ++j) {
			fscanf(fin, "%c", &palya[i][j]);
			//palya[i][j] = rand() % 5;
		}
	}

	for (int i = 0; i < szel; ++i) {
		//scanf("%c", palya[i]);
		for (int j = 0; j < hossz; ++j) {
			//keret
			printf("%c", palya[i][j]);

			if (palya[i][j] == 3) {
				printf("x");
			}

			/*if ( i==0 || i == szel - 1 ) {
				printf("-");
			}
			else if(j == 0 || j == hossz - 1) {
				printf("|");
			}

			else if (i == 1 || i == szel - 2) {
				printf(" ");
			}
			else if (j == 1 || j == hossz - 2) {
				printf("x");
			}
			else if (i == 2 || i == szel - 3) {
				printf(" ");
			}
			else if (j == 2 || j == hossz - 3) {
				printf(" ");
			}
			else if (i == 3 || i == szel - 4) {
				printf("O");
			}	*/
		}
		printf("\n");
	}

	return palya;
}
