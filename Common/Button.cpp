#include "Button.h"
#include <iostream>

using namespace std;

Button::Button() {
	setHeight(1);
};

Button::Button(string & s)
{
	this->setValue(s);
};


void Button::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugStringW(L"Button::mousePressed\n");
	//CLogger::GetLogger()->Log("mouse pressed");
	//CLogger::GetLogger()->Log("COORD %d ,%d , %d ", x, y, left);
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {
		OutputDebugStringW(L"Button::mousePressed in inside !!! \n");
		// call to Action
		for (MouseListener* listener : listeners) {
			listener->MousePressed(x, y, isLeft);
		}
	// unsigned sz = s.size();
	// s.resize(sz + 2, ' ');
	}
}

void Button::draw(Graphics& g, short x, short y, size_t z)
{
	Control::draw(g, x, y, z);
	//CLogger::GetLogger()->Log("DRAW BUTTON");
	//OutputDebugStringW(L"Button::draw\n" );
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write( getValue() );
}

void Button::keyDown(WORD keyCode, char charecter) {};
