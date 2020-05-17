#ifndef LEVEL_H
#define LEVEL_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

char** beolvas(const char* filename,int hossz, int szel);
void Print(char** palya, int hossz, int szel);
#endif
