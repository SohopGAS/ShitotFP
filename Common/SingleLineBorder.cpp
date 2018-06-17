#include "SingleLineBorder.h"
#include <iostream>

BorderType* SingleLineBorder::instance = NULL;

//singleton instance
BorderType* SingleLineBorder::getinstance() {
	if (!instance)
		instance = new SingleLineBorder();

	return instance;
}

void SingleLineBorder::drawBorder(COORD start, COORD size)
{
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//draw upper line
	SetConsoleCursorPosition(handle, start);
	for (short i = 0; i<size.X; i++)

		for (short i = 1; i<size.Y - 1; i++)
		{
			//draw left and right lines
			SetConsoleCursorPosition(handle, { start.X, start.Y + i });
			cout << "*";
			SetConsoleCursorPosition(handle, { start.X + size.X, start.Y + i });
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
