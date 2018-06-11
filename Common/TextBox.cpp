#include "TextBox.h"



TextBox::TextBox()
{
}


TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g, int x, int y, size_t z) {
	//g.setCursorVisibility(true);
	g.setBackground(Color::Red);
	g.moveTo(10, 10);
	
	g.write(1,1,this->_value);
	
	
}

void TextBox::keyDown(int keyCode, char charecter) {
	//graphics.moveTo(this->_position.X + 2, this->_position.Y + 2);
	//this->value = string(1, ch);
	//graphics.write(string(1, ch));
}

void TextBox::mousePressed(int x, int y, bool isLeft) {

}