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
	bool mouse_clicked = false;
	POINT cursorPostion;
	int mX, mY;
	cursorPostion.y = y;
	cursorPostion.x = x;
	string message = "mouse_cliecked";
	int    nNum = 10;
	if (isLeft)
	{

		mX = cursorPostion.x;
		mY = cursorPostion.y;
		GetCursorPos(&cursorPostion);

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			mouse_clicked = true;




		}
		

	}
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

