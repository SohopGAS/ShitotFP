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
	cout << TOP_LEFT;
	for (short i = 0; i<_width-1; i++)
		cout << LINE_HORIZONTAL;
	cout << TOP_RIGHT;

	for (int i = 1; i<_height-1; i++)
	{
		g.moveTo(newXPos, newYPos + i); 
		cout << LINE_VERTICAL;
		g.moveTo(newXPos + _width, newYPos + i);
		cout << LINE_VERTICAL;
	}

	g.moveTo(newXPos, newYPos+ _height-1);
	cout << BTM_LEFT;
	for (short i = 0; i<_width-1; i++)
		cout << LINE_HORIZONTAL;
	cout << BTM_RIGHT;

	/*
	cout << TOP_LEFT;
	g.moveTo(newXPos+ _width, newYPos);
	cout << TOP_RIGHT;
	g.moveTo(newXPos, newYPos+ _height-1);
	cout << BTM_LEFT;
	g.moveTo(newXPos+_width, newYPos + _height-1);
	cout << BTM_RIGHT;
	g.moveTo(newXPos+1, newYPos);
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
*/
}


SingleLineBorder::~SingleLineBorder()
{
}
