#include "TextBox.h"

TextBox::TextBox()
{
}

<<<<<<< HEAD
=======
TextBox::TextBox(short _left = 0, short _top = 0, short _width = 0, short _height = 0) : Control()
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}


>>>>>>> master
TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g, int x, int y, size_t z) {
	//g.setCursorVisibility(true);
<<<<<<< HEAD
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

=======
	//g.setBackground(ColorType::Red);
	//g.moveTo(10, 10);
	//g.write(1,1,this->value);
	// char* fn = __FUNCTION__;
	Control::draw(g, 10, 10, 2);
	setValue("heeyyyyyy");


}


void TextBox::keyDown(int keyCode, char charecter) {

}
>>>>>>> master
void TextBox::mousePressed(int x, int y, bool isLeft) {

}
