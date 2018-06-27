#include "TextBox.h"

TextBox::TextBox()
{
	setLeft(0);
	setTop(0);
	setWidth(3);
	setHeight(1);

}

TextBox::TextBox(short _left = 0, short _top = 0, short _width = 10, short _height = 1) : Control()
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}


TextBox::~TextBox()
{
}

void	TextBox::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, x, y, z);

//	OutputDebugStringW(L"TextBox::draw\n");

	g.setCursorVisibility(true);
	g.write(left + 1, top + 1, value);
	g.moveTo(left + value.size(), top);

}


void TextBox::keyDown(int keyCode, char charecter) {
	OutputDebugStringW(L"TextBox::keyDown\n");
}
void TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g) {

	OutputDebugStringW(L"TextBox::mousePressed\n");

	g.setCursorVisibility(true);
	g.setBackground(bg);
	g.setForeground(fg);
}
//
//void TextBox::keyDown(WORD code, CHAR c) {
//	if (code == 0x46) { // F key for debaging
//		string str = "";
//		_graphics.write(10, 10, _value);
//		getchar();
//	}
//	if (_value.size() < _width - 2) {
//		if (c >= ' ' && c <= '~') {
//			cout << c;
//			if (_value.size() == logicalPosition - 1) {
//				_value += c;
//			}
//			else {
//				char temp[] = { c };
//				_value.insert(logicalPosition, temp, 1);
//			}
//			graphics.moveTo(_left + 1 + _value.size(), _top + 1);
//			logicalPosition++;
//			return;
//		}
//	}
//
//	switch (code) {
//	case VK_RIGHT: {
//
//		if (_value.size() < _width - 3) {
//			logicalPosition++;
//			_value += " ";
//			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
//		}
//		break;
//	}
//	case VK_LEFT: {
//		if (logicalPosition >= 1) {
//			logicalPosition--;
//			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
//		}
//		break;
//	}
//
//	case VK_BACK: {
//		if (logicalPosition  > 0) {
//			logicalPosition--;
//			_value.erase(logicalPosition, 1);
//		}
//		break;
//	}
//
//	case VK_DELETE: {
//		if (logicalPosition > 0) {
//
//			_value.erase(logicalPosition, 1);
//		}
//		break;
//	}
//
//	}
//}
//
//
//void TextBox::mousePressed(int x, int y, bool ifFirstButton) {
//	
//		int pressed = x - this->getLeft() - 2;
//		int yTest = y;
//		if (pressed >= value.size() || (yTest != this->getTop() + 2)) { //checking if the mouse is on the textbox.
//			return;
//		
//		Control::setFocus(*this);
//
//		logicalPosition = pressed;
//	
//}

