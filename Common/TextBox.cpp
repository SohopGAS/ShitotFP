#include "TextBox.h"

TextBox::TextBox()
{

}

TextBox::TextBox(short _left = 0, short _top = 0, short _width = 0 , short _height = 1) : Control()
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

	g.setCursorVisibility(true);
	g.moveTo(left, top);
	g.write(value);
}


void TextBox::keyDown(WORD keyCode, char charecter) {
	if (value.size() < width - 2) {
		if (charecter >= ' ' && charecter <= '~') {
						//cout << charecter;
						 if (value.size() == logicalPosition - 1) {
							value += charecter;
							}
						 else {
							char temp[] = { charecter };
							value.insert(logicalPosition, temp, 1);
						}
						//graphic.moveTo(getLeft() + 1 + value.size(), getTop() + 1);
						logicalPosition++;
						return;
						}
						}
						switch (keyCode) {
						case VK_RIGHT: {
						
								if (value.size() < getWidth() - 3) {
									logicalPosition++;
									value += " ";
									//graphic.moveTo(getLeft() + 1 + value.size(), getTop() + 1);
								}
								break;
							}
						case VK_NUMPAD6: {

							if (value.size() < getWidth() - 3) {
								logicalPosition++;
								value += " ";
								//graphic.moveTo(getLeft() + 1 + value.size(), getTop() + 1);
							}
							break;
							}
							case VK_LEFT: {
								if (logicalPosition >= 1) {
									logicalPosition--;
									//graphic.moveTo(getLeft() + 1 + value.size(), getTop() + 1);
								}
								break;
							}
							case VK_NUMPAD4: {
								if (logicalPosition >= 1) {
									logicalPosition--;
									//graphic.moveTo(getLeft() + 1 + value.size(), getTop() + 1);
								}
								break;
							}
						
							case VK_BACK: {
								if (logicalPosition  > 0) {
									logicalPosition--;
									value.erase(logicalPosition, 1);
								}
								break;
							}
						
							case VK_DELETE: {
								if (logicalPosition > 0) {
						
									value.erase(logicalPosition, 1);
								}
								break;
							}
						
						}
	}
						

void TextBox::mousePressed(int x, int y, bool isLeft) {

	OutputDebugStringW(L"TextBox::mousePressed\n");

//	g.setCursorVisibility(true);
//	g.setBackground(bg);
//	g.setForeground(fg);

	if (isInside(x, y, this->getLeft(), this->getTop(), this->getWidth(), this->getHeight())) {
		if (x > ( getLeft() + value.size() )) {
			graphic.moveTo(getLeft()+value.size(),getTop());
			logicalPosition = value.size();
		}
		else if(isLeft){
			graphic.moveTo(x , getTop());
			logicalPosition = x - getLeft();
		}
		//Control::setFocus(*this);
		//focusOn();
		
	}
	return;
	
}

