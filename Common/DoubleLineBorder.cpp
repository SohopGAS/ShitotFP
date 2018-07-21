#include <iostream>

#include "DoubleLineBorder.h"

BorderType* DoubleLineBorder::instance = NULL;

BorderType* DoubleLineBorder::getinstance() {
	if (!instance)
		instance = new DoubleLineBorder();
	return instance;
}

void DoubleLineBorder::drawBorder(Graphics& g,short start_x, short start_y, short _width, short _height)
{
	short newYPos = start_y;
	short newXPos = start_x;
	g.moveTo(newXPos, newYPos);
	cout << TOP_LEFT;

	for (short i = 0; i<_width - 1; i++)
		cout << LINE_HORIZONTAL;

	cout << TOP_RIGHT;

	for (int i = 1; i<_height - 1; i++)
	{
		g.moveTo(newXPos, newYPos + i);
		cout << LINE_VERTICAL;
		g.moveTo(newXPos + _width, newYPos + i);
		cout << LINE_VERTICAL;
	}

	g.moveTo(newXPos, newYPos + _height - 1);
	cout << BTM_LEFT;

	for (short i = 0; i<_width - 1; i++)
		cout << LINE_HORIZONTAL;

	cout << BTM_RIGHT;
}

DoubleLineBorder::~DoubleLineBorder()
{}
