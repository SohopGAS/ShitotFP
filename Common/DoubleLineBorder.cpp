#include "DoubleLineBorder.h"
#include <iostream>

BorderType* DoubleLineBorder::instance = NULL;

BorderType* DoubleLineBorder::getinstance() {

	if (!instance)
		instance = new DoubleLineBorder();

	return instance;
}


void DoubleLineBorder::drawBorder(Graphics& g,short start_x, short start_y, short width, short height)
{
	
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD start = { start_x, start_y };
	COORD size = { width, height };


	SetConsoleCursorPosition(handle, start);
	for (short i = 0; i<size.X; i++)

	for (short i = 1; i<size.Y - 1; i++)
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

DoubleLineBorder::~DoubleLineBorder()
{
}
