#include "Button.h"
#include <iostream>

using namespace std;


Button::Button() {
	listeners = 0;
};

Button::Button(string& s)
{
	expand_string(s);
};


Button::~Button() {

};

void Button::setValue(string s)
{
	expand_string(s);
	Label::setValue(s);
}




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


void Button::expand_string(string& s) {
	unsigned int sz = s.size();
	s.resize(sz + 2, ' ');
}



void Button::draw(Graphics& g, short x, short y, size_t z)
{
	CLogger::GetLogger()->Log("DRAW BUTTON");
	Label::draw(g, x, y, z);
}
