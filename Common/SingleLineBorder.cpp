#include "SingleLineBorder.h"
#include <iostream>

BorderType* SingleLineBorder::instance = NULL;

//singleton instance
BorderType* SingleLineBorder::getinstance() {
	if (!instance)
		instance = new SingleLineBorder();

	return instance;
}

void SingleLineBorder::drawBorder(Graphics& g,short start_x, short start_y, short width, short height)
{
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD start = { start_x, start_y };
	COORD size = { width, height };
	//draw upper line
	SetConsoleCursorPosition(handle, start);
	for (short i = 0; i<size.X; i++)

		for (short j = 1; j<size.Y - 1; j++)
		{
			//draw left and right lines
			SetConsoleCursorPosition(handle, { start.X, start.Y + j });
			cout << "*";
			SetConsoleCursorPosition(handle, { start.X + size.X, start.Y + j });
			cout << "*";
		}
	//draw bottom line
	SetConsoleCursorPosition(handle, { start.X, start.Y + size.Y });
	for (int i = 0; i<size.X; i++)
		cout << '*';

}


SingleLineBorder::~SingleLineBorder()
{
}
