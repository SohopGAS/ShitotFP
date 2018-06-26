#pragma once
#include "Button.h"
#include <iostream>

using namespace std;

void Button::mousePressed(int x, int y, bool isLeft)
{
	CLogger::GetLogger()->Log("mouse pressed");
	CLogger::GetLogger()->Log("COORD %d ,%d , %d ", x, y, left);
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {

		for (MouseListener* listener : listeners) {
			listener->MousePressed(x, y, isLeft);
		}

	}

}

void Button::draw(Graphics& g, short x, short y, size_t z)
{	

	
	//Control::draw(g, x, y, z);
	//g.moveTo(getLeft()+3, getTop()+5);
	CLogger::GetLogger()->Log("mouse pressed Button");
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft()+3, getTop()+3);
	g.setCursorVisibility(true);
	//setValue("+");
	if (!z)
		g.write(value);
	g.setBackground(ColorType::Orange);
	g.setForeground(ColorType::Red);

	CLogger::GetLogger()->Log("DRAW BUTTON");
	
	Label::draw(g, x, y, z);
	
	
}