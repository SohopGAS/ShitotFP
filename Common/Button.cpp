#include "Button.h"
#include <iostream>

using namespace std;

void Button::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugStringW(L"Button::mousePressed\n");

	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {
		OutputDebugStringW(L"Button::mousePressed in inside !!! \n");
		// call to Action
		for (MouseListener* listener : listeners) {
			listener->MousePressed(x, y, isLeft);
		}
	}
}

void Button::draw(Graphics& g, short x, short y, size_t z)
{
	Control::draw(g, x, y, z);

	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write( getValue() );
}

void Button::keyDown(WORD code, char charecter) {}
