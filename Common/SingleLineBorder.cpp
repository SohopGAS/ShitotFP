#include "SingleLineBorder.h"
#include <iostream>

BorderType* SingleLineBorder::instance = NULL;

//singleton instance
BorderType* SingleLineBorder::getinstance() {
	if (!instance)
		instance = new SingleLineBorder();

	return instance;
}

void SingleLineBorder::drawBorder(Graphics& g,short start_x, short start_y, short _width, short _height)
{
	//auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD start = { start_x, start_y };
	//COORD size = { _width, _height };

	short newYPos = start_y;
	short newXPos = start_x;
	g.moveTo(newXPos, newYPos);
	for (int rows = 0; rows <_height; rows++) {
		for (int col = 0; col < _width; col++) {
			if (col == 0 || col == (_width - 1) || rows == 0 || (rows == _height - 1)) {
				if (rows == 0 || (rows == _height - 1)) {
					cout << LINE_HORIZONTAL;
				}
				else {
					cout << LINE_VERTICAL ;
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		newYPos++;
		g.moveTo(newXPos, newYPos);
	}

}


SingleLineBorder::~SingleLineBorder()
{
}
