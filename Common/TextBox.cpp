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

TextBox::TextBox(short _left = 0, short _top = 0, short _width = 0, short _height = 0) : Control()
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
{
	setLeft(_left);
	setTop(_top);
	setWidth(_width);
	setHeight(_height);
}


<<<<<<< HEAD
TextBox::~TextBox()
{
}

void	TextBox::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, x, y, z);

//	OutputDebugStringW(L"TextBox::draw\n");
=======
TextBox::~TextBox() {}
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff

	g.setCursorVisibility(true);
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
}


void TextBox::keyDown(int keyCode, char charecter) {
<<<<<<< HEAD
	OutputDebugStringW(L"TextBox::keyDown\n");
}
void TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g) {
=======
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
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff

	OutputDebugStringW(L"TextBox::mousePressed\n");

	g.setCursorVisibility(true);
	g.setBackground(bg);
	g.setForeground(fg);
}
//
//void TextBox::keyDown(WORD code, CHAR c) {
//	if (code == 0x46) { // F key for debaging
//		string str = "";
//		_graphics.write(10, 10, _value);
//		getchar();
//	}
//	if (_value.size() < _width - 2) {
//		if (c >= ' ' && c <= '~') {
//			cout << c;
//			if (_value.size() == logicalPosition - 1) {
//				_value += c;
//			}
//			else {
//				char temp[] = { c };
//				_value.insert(logicalPosition, temp, 1);
//			}
//			graphics.moveTo(_left + 1 + _value.size(), _top + 1);
//			logicalPosition++;
//			return;
//		}
//	}
//
//	switch (code) {
//	case VK_RIGHT: {
//
//		if (_value.size() < _width - 3) {
//			logicalPosition++;
//			_value += " ";
//			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
//		}
//		break;
//	}
//	case VK_LEFT: {
//		if (logicalPosition >= 1) {
//			logicalPosition--;
//			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
//		}
//		break;
//	}
//
//	case VK_BACK: {
//		if (logicalPosition  > 0) {
//			logicalPosition--;
//			_value.erase(logicalPosition, 1);
//		}
//		break;
//	}
//
//	case VK_DELETE: {
//		if (logicalPosition > 0) {
//
//			_value.erase(logicalPosition, 1);
//		}
//		break;
//	}
//
//	}
//}
//
//
//void TextBox::mousePressed(int x, int y, bool ifFirstButton) {
//
//		int pressed = x - this->getLeft() - 2;
//		int yTest = y;
//		if (pressed >= value.size() || (yTest != this->getTop() + 2)) { //checking if the mouse is on the textbox.
//			return;
//
//		Control::setFocus(*this);
//
//		logicalPosition = pressed;
//
//}
// <<<<<<< HEAD
// void TextBox::keyDown(int keyCode, char charecter) {
// 	if (keyCode == VK_NUMPAD4 || keyCode == VK_LEFT) {
// 		// todo: left button
//
// 	}
// 	else if (keyCode == VK_NUMPAD6 || keyCode == VK_RIGHT) {
// 		// todo: right button
// 	}
// 	else if (keyCode == VK_NUMPAD8 || keyCode == VK_UP) {
// 		// todo: up button
// 	}
// 	else if (keyCode == VK_NUMPAD2 || keyCode == VK_DOWN) {
// 		// todo: down button
// 	}
// 	else if (keyCode == VK_BACK) {
// 		// todo: backspace button
// 	}
// 	else if (keyCode == VK_TAB) {
// 		// todo: tab button
// 	}
// 	else if (keyCode == VK_RETURN) {
// 		// todo: return/enter button
// 	}
// 	else if (keyCode == VK_DELETE) {
// 		// todo: delete button
// 	}
// 	else if ((keyCode >= 0x30 && keyCode <= 0x39) || (keyCode >= 0x60 && keyCode <= 0x69)) {
// 		// todo: number button
// 		setValue(value + charecter);
// 	}
// 	else if (keyCode >= 0x41 && keyCode <= 0x5A) {
// 		// todo: capital letter button
// 		//CLogger
// 		setValue(getValue() + charecter);
// 	}
// }

//
// void TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g) {
// 	g.setCursorVisibility(true);
// 	g.setBackground(bg);
// 	g.setForeground(fg);
// }
// =======

// >>>>>>> 8aaa4697a50fd0e495817660898b3347455311b4
