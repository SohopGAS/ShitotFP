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
	
	g.setCursorVisibility(true);
	if (!z)
		g.write(value);
	g.setBackground(ColorType::Black);
	g.setForeground(ColorType::White);


	
//	g.write(this->_value);
}


void TextBox::keyDown(int keyCode, char charecter) {
	CLogger::GetLogger()->Log("DRAW TEXTBox");

}
void TextBox::mousePressed(int x, int y, bool isLeft) {

}
