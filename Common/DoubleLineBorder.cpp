#include "DoubleLineBorder.h"
#include <iostream>


static DoubleLineBorder*:: getinstance() {
	if (!instance)
		instance = new DoubleLineBorder();

	return instance;
}

DoubleLineBorder::DoubleLineBorder() : BorderType() {};

void DoubleLineBorder::drawBorder(COORD start, COORD size)
{
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, start);
	for (int i = 0; i<size.X; i++)

	for (int i = 1; i<size.Y - 1; i++)
	{
		SetConsoleCursorPosition(handle, { start.X, start.Y + i });
		cout << "*";
		SetConsoleCursorPosition(handle, { start.X + size.X, start.Y + i });
		cout << "*";
	}

	SetConsoleCursorPosition(handle, { start.X, start.Y + size.Y });
	for (int i = 0; i<size.X; i++)
		cout << '*';

}

