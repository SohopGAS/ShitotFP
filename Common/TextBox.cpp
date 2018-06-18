#include "TextBox.h"

TextBox::TextBox()
{
}


TextBox::TextBox(short _left = 0, short _top = 0, short _width = 10, short _height = 10) : Control()
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}


TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g, short x, short y, size_t z) {
	g.setCursorVisibility(true);
	g.setBackground(ColorType::Red);
	g.moveTo(10, 10);
	g.write(1,1,this->value);
	// char* fn = __FUNCTION__;
	Control::draw(g, 10, 10, 2);
	setValue("heeyyyyyy");


void TextBox::draw(Graphics& g, short x, short y, size_t z) {
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
}


void TextBox::keyDown(int keyCode, char charecter) {
	if (value.size() < width - 2) {//check if you can change the content in textbox
		if (charecter > '\x1F' && charecter < '\x7F') {//check if value is not a navigation key
			int s = value.size();
			if (s == presscount) {
				value += charecter;
			}
			else {
				value.insert(presscount -1, &charecter, 1);
			}
			presscount++;
			//++_cursorPosition;
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
		if (presscount < width) {
			++presscount;
		}
		break;
	}
	case VK_LEFT: {
		if (presscount > 0) {
			--presscount;
		}
		break;
	}
	case VK_BACK: {


	}
	case VK_DELETE: {
		if (presscount > 0) {
		 std::string str = " ";
		 --presscount;
		 value.erase(presscount);
		}
		break;
	}
	}
}



void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (isLeft == FALSE)
		return;
}


bool TextBox::canGetFocus() {

}
