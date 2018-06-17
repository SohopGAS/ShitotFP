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

void TextBox::draw(Graphics& g, int x, int y, size_t z) {
	//g.setCursorVisibility(true);
	//g.setBackground(ColorType::Red);
	//g.moveTo(10, 10);
	//g.write(1,1,this->value);
	// char* fn = __FUNCTION__;
	Control::draw(g, 10, 10, 2);
	setValue("heeyyyyyy");


}


void TextBox::keyDown(int keyCode, char charecter) {
	// switch (keyDown) {
	// 	case VK_LEFT:
	// 		cursorPosition = left + value.size();
	//
	// 	case VK_RIGHT:
	// 		moveTo(x + 1, y);
	//
	//
	// }


}



void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (isLeft == FALSE)
		return;


}


bool TextBox::canGetFocus() {

}
