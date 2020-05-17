#include "Level.h"
#include "Player.h"
#include "Enemy.h"


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <Windows.h>

int main() {

	printf("Vidd a sajtot(#) az egerlyukhoz(O)! Vigyazz a macskakara(&) es az egerfogokra(x)!\n");
	Sleep(2000);
	system("CLS");

	char** palya = beolvas("Text.txt",16,8);
	Player* player = CreateP(palya, 16, 8);
	Enemy* enemy = CreateE(palya, 16, 8);
	Print(palya, 16, 8);
	
	time_t current, start;
	start = time(NULL);
	int ch;
	while (1) {
		current = time(NULL);
		ch = getch();
		if (ch == 'q') {
			break;
		}
		if (player->health == 0) {
			printf("Megfogott a macska!\n");
			break;
		}
		Input(ch, player, palya);
		InputE(enemy, palya);
		system("CLS");
		Print(palya, 16, 8);
		Sleep(200);

		if (current - start > 10) {
			system("CLS");
			printf("Lejart az ido!\n\nA megszerzett sajtok szama: ");
			Points(palya, player, 16, 8);
			Sleep(200);
			printf("A folytatashoz nyomd meg a 'q' betut!\n");
		}	
	}
	
	start = time(NULL);
	char** palya2 = beolvas("Text2.txt", 24, 12);
	player = CreateP(palya2, 24, 12);
	enemy = CreateE(palya2, 24, 12);
	Enemy* enemy2 = CreateE(palya2, 24, 12);
	Enemy* enemy3 = CreateE(palya2, 24, 12);
	Print(palya2, 24, 12);
	while (1) {
		current = time(NULL);
		ch = getch();
		if (ch == 'q') {
			break;
		}
		if (player->health == 0) {
			printf("megfogott a macska!");
			break;
		}
		Input(ch, player, palya2);
		InputE(enemy, palya2);
		InputE(enemy2, palya2);
		InputE(enemy3, palya2);
		system("CLS");
		Print(palya2, 24,12);
		Sleep(200);
		if (current - start > 20) {
			system("CLS");
			printf("Lejart az ido!\n\nA megszerzett sajtok szama: ");
			Points(palya2, player, 24, 12);
			Sleep(200);
			printf("A folytatashoz nyomd meg a 'q' betut!\n");
			}
	}

	palya = beolvas("Text3.txt", 30, 15);
	player = CreateP(palya, 30, 15);
	Enemy* enemy4 = CreateE(palya, 30, 15);
	Enemy* enemy5 = CreateE(palya, 30, 15);
	Enemy* enemy6 = CreateE(palya, 30, 15);
	Enemy* enemy7 = CreateE(palya, 30, 15);
	Print(palya, 30, 15);
	start = time(NULL);
	while (1) {
		current = time(NULL);
		ch = getch();
		if (ch == 'q') {
			break;
		}
		if (player->health == 0) {
			printf("megfogott a macska!");
			break;
		}
		Input(ch, player, palya);
		InputE(enemy4, palya);
		InputE(enemy5, palya);
		InputE(enemy6, palya);
		InputE(enemy7, palya);
		system("CLS");
		Print(palya, 30, 15);
		Sleep(200);
		if (current - start > 20) {
			system("CLS");
			printf("Lejart az ido!\n\nA megszerzett sajtok szama: ");
			Points(palya, player, 30,15);
			Sleep(200);
		}
	}
		return 0;
}