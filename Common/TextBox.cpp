#include "TextBox.h"

// constrctor
TextBox::TextBox()
{
	setLeft(0);
	setTop(0);
	setWidth(3);
	setHeight(1);
}

// parmeters constractor
TextBox::TextBox(short _left = 0, short _top = 0, short _width = 10, short _height = 1) : Control()
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}

// destrctor
TextBox::~TextBox()
{}

// implement draw 
void TextBox::draw(Graphics& g, short x, short y, size_t z) 
{
	// draw border
	Control::draw(g, x, y, z);
	g.moveTo(left, top);
	g.write(value);
}


// implement keyDown
void TextBox::keyDown(WORD keyCode, char charecter) {
	if (value.size() < width - 2) {
		if (charecter >= ' ' && charecter <= '~') {
			if (value.size() == logicalPosition - 1) {
				value += charecter;
			}
			else {
				char temp[] = {charecter};
				value.insert(logicalPosition, temp, 1);
			}
			logicalPosition++;
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
		if (value.size() < getWidth() - 3) {
			logicalPosition++;
			value += " ";
		}
		break;
	}
	case VK_NUMPAD6: {
		if (value.size() < getWidth() - 3) {
			logicalPosition++;
			value += " ";
		}
		break;
	}
	case VK_LEFT: {
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		break;
	}
	case VK_NUMPAD4: {
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		break;
	}
	case VK_BACK: {
		if (logicalPosition  > 0) {
			logicalPosition--;
			value.erase(logicalPosition, 1);
		}
		break;
	}
	case VK_DELETE: {
		if (logicalPosition > 0) {
			value.erase(logicalPosition, 1);
		}
		break;
	} // end lase case
	} // end switch
}

// implements mousePressed
void TextBox::mousePressed(int x, int y, bool isLeft) 
{
	if (isInside(x, y, this->getLeft(), this->getTop(), this->getWidth(), this->getHeight())) {
		if (x > (getLeft() + value.size())) {
			graphic.moveTo(getLeft() + value.size(), getTop());
			logicalPosition = value.size();
		}
		else if (isLeft) {
			graphic.moveTo(x, getTop());
			logicalPosition = x - getLeft();
		}
		Control::setFocus(*this);
	}
	return;
}


// implement focusOn - change cursor position 
void TextBox::focusOn()
{
	graphic.moveTo(left + logicalPosition, top);
	graphic.setCursorVisibility(true);
}
