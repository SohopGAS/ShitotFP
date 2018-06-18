#include "TextBox.h"

TextBox::TextBox()
{
}

TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, x, y, z);
	g.moveTo(getLeft(), getTop());

	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	g.setCursorVisibility(true);
	if (!z)
		g.write(_value);
	g.setBackground(Color::Black);
	g.setForeground(Color::White);


	
//	g.write(this->_value);
}

void TextBox::keyDown(int keyCode, char charecter) {
	/*
	if (_value.size() < width - 2) {//check if you can change the content in textbox
		if (charecter > '\x1F' && charecter < '\x7F') {//check if value is not a navigation key
			printf("%c", charecter);
			if (_value.size() == _cursorPosition - 1) {
				_value += charecter;
			}
			else {
				_value.insert(_cursorPosition, &charecter, 1);
			}
			Control::graphics.moveTo(left + _value.size() + 1, top + 1);
			++_cursorPosition;
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
		if (_cursorPosition < _width) {
			++_cursorPosition;
			Control::graphics.moveTo(_left - _value.size() - 1, _top + 2);
		}
		break;
	}
	case VK_LEFT: {
		if (_cursorPosition > 0) {
			--_cursorPosition;
			Control::graphics.moveTo(_left + _value.size() + 1, _top + 2);
		}
		break;
	}
	case VK_BACK: {
		if (_cursorPosition  > 0) {
			--_cursorPosition;
			_value.erase(_cursorPosition, 1);
		}
		break;
	}
	case VK_DELETE: {
		if (_cursorPosition > 0) {
			_value.erase(_cursorPosition, 1);
		}
		break;
	}
	}
	*/
}

void TextBox::mousePressed(int x, int y, bool isLeft) {

}