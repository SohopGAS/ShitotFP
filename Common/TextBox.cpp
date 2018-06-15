#include "TextBox.h"

TextBox::TextBox()
{
}

TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g, int x, int y, size_t z) {
	//g.setCursorVisibility(true);
	g.setBackground(ColorType::Red);
	g.moveTo(10, 10);

	g.write(1,1,this->value);

}

void TextBox::keyDown(int keyCode, char charecter) {
/*
	//check if you can change the content in textbox
	if (_value.size() < width - 2) {
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
	}*/
}

void TextBox::mousePressed(int x, int y, bool isLeft) {

}
