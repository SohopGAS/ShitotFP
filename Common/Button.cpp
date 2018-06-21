#include "Button.h"
#include <iostream>

using namespace std;

void Button::mousePressed(int x, int y, bool isLeft)
{
	CLogger::GetLogger()->Log("mouse pressed");
	CLogger::GetLogger()->Log("COORD %d ,%d , %d ", x, y, left);
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {

		//for (MouseListener* listener : listeners) {
		//	listener->MousePressed(x, y, isLeft);
		//}

	}

}

void Button::draw(Graphics& g, short x, short y, size_t z)
{
	Control::draw(g, x, y, z);
	CLogger::GetLogger()->Log("DRAW BUTTON");
	Label::draw(g, x, y, z);
}
