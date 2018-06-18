#include "Button.h"
#include <iostream>

using namespace std;

Button::Button(string & s)
{
	expand_string(s);	
}

void Button::setValue(string s)
{
	expand_string(s);
	Label::setValue(s);
}




void Button::mousePressed(int x, int y, bool isLeft)
{
	CLogger::GetLogger()->Log("mouse pressed");

//	if (isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height)) {
	///	for (MouseListener* listener : listeners) {
		//	listener->MousePressed(x, y, isLeft);
	//	}
	//}

}


void Button::expand_string(string &s) {

	unsigned sz = s.size();
	s.resize(sz + 2, ' ');
	
}



void Button::draw(Graphics& g, int x, int y, size_t z)
{
	CLogger::GetLogger()->Log("DRAW BUTTON");
	Label::draw(g, x, y, z);
}


