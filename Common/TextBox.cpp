#include "TextBox.h"

TextBox::TextBox()
{
	setLeft(0);
	setTop(0);
	setWidth(3);
	setHeight(1);

}

<<<<<<< HEAD
TextBox::TextBox(short _left = 0, short _top = 0, short _width = 10, short _height = 1) : Control()
=======

<<<<<<< HEAD
TextBox::TextBox(short _left = 0, short _top = 0, short _width = 10, short _height = 10) : Control()
=======
TextBox::TextBox(short _left = 0, short _top = 0, short _width = 0, short _height = 0) : Control()
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
>>>>>>> master
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}


<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> master
TextBox::~TextBox()
{
}

<<<<<<< HEAD
void TextBox::draw(Graphics& g, short int x, short int y, size_t z) {
	g.setCursorVisibility(true);
	g.setBackground(ColorType::Red);
	g.moveTo(10, 10);
	g.write(1,1,this->value);
	// char* fn = __FUNCTION__;
	Control::draw(g, 10, 10, 2);
	setValue("heeyyyyyy");
=======
void	TextBox::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, x, y, z);

//	OutputDebugStringW(L"TextBox::draw\n");
=======
TextBox::~TextBox() {}
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff

	g.setCursorVisibility(true);
<<<<<<< HEAD
	g.write(left + 1, top + 1, value);
	g.moveTo(left + value.size(), top);

void TextBox::draw(Graphics& g, short x, short y, size_t z) {
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
	// // if (z == getZIndex()) {
	// y = this->getTop();
	// x = this->getLeft();
	// // draw(g, panelLeft, panelTop, z);
	// g.setCursorVisibility(true);
	// g.setBackground(this->bg);
	// g.setForeground(this->fg);
	//
	// g.moveTo(getLeft(), getTop());
	// if (!z)
	// 	g.write(value);
	//
	//
	//
	// g.write(left + 1, top + 1, value);
	// g.moveTo(left + 1 + value.size(), top + 1);
	// //}
>>>>>>> master
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
=======
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
>>>>>>> e4194c59f25c5d0d7c4b091f1538e719195407b4
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
<<<<<<< HEAD
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

	OutputDebugStringW(L"TextBox::mousePressed\n");

	g.setCursorVisibility(true);
	g.setBackground(bg);
	g.setForeground(fg);
=======

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

	if (isInside(x, y, this->getLeft(), this->getTop(), this->getWidth(), this->getHeight())) {
		if (x > (getLeft() + value.size())) {
			graphic.moveTo(getLeft() + value.size(), getTop());
			logicalPosition = value.size();
		}
		else if (isLeft) {
			graphic.moveTo(x, getTop());
			logicalPosition = x - getLeft();
		}
		Control::setFocus(*this);
		focusOn();

	}
	return;

>>>>>>> e4194c59f25c5d0d7c4b091f1538e719195407b4
}
