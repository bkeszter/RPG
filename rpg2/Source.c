#include "Level.h"
#include "Player.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

int main() {

	char** palya = beolvas("Text.txt",8,7);
	Player* player = CreateP(palya, 8,7);

	return 0;
}