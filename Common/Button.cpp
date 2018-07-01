#include "Button.h"
#include <iostream>

using namespace std;

<<<<<<< HEAD
Button::Button() {
	
};

Button::Button(string & s)
{
	expand_string(s);
}

void Button::setValue(string s)
=======
void Button::mousePressed(int x, int y, bool isLeft)
>>>>>>> master
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

<<<<<<< HEAD
	unsigned sz = s.size();
	s.resize(sz + 2, ' ');

=======
	}
>>>>>>> master
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
<<<<<<< HEAD
=======

void Button::keyDown(WORD keyCode, char charecter) {

}
>>>>>>> master
