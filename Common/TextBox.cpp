#include "TextBox.h"

TextBox::TextBox()
{
}

TextBox::TextBox(short _left = 0, short _top = 0, short _width = 0, short _height = 0) : Control()
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

}
void TextBox::mousePressed(int x, int y, bool isLeft) {

}
