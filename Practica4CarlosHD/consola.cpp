#include "stdafx.h"
#include <windows.h>
#include <assert.h>

const bool CHECK_COORD_VALUES = (sizeof(SHORT) < sizeof(int));

// ***************************************************************************************
// FUNCIONES AUXILIARES DE PINTADO
// ***************************************************************************************
void gotoxy(int x, int y)
{
	if (CHECK_COORD_VALUES)
	{
		// If x and y could overflow the size of a SHORT, this breaks if it happens
		assert((x >= 0 && x < SHRT_MAX) || (x < 0 && x > SHRT_MIN));
		assert((y >= 0 && y < SHRT_MAX) || (y < 0 && y > SHRT_MIN));
	}

	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
	system("cls");
}

int getConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		return (csbi.srWindow.Right - csbi.srWindow.Left + 1);
	}
	else
		return 0;
}

int getConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		return (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
	}
	else
		return 0;
}