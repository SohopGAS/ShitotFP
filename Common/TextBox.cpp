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
	Control::draw(g, x, y, z);

	g.setCursorVisibility(true);
	g.setBackground(ColorType::Red);
	g.setForeground(ColorType::Black);
	g.moveTo(x, y);

	// char* fn = __FUNCTION__;
	Control::draw(g, 10, 10, 2);
	setValue("heeyyyyyy");
}


void TextBox::keyDown(int keyCode, char charecter) {

}
void TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g) {
	g.setCursorVisibility(true);
	g.setBackground(bg);
	g.setForeground(fg);
}
