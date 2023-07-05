#pragma once

#include <iostream>
#include <vector>
#include <memory>


#ifdef _WIN32
	#include <Windows.h>

void gotoxy(int x, int y) {
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	#include <unistd.h>
	#define gotoxy(x, y) printf("\033[%d;%dH", y, x)
#endif


#define MAX_ROWS 1000
#define MAX_COLS 1000




