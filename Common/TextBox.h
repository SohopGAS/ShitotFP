#include "Control.h"
/*
* This is a class of "one line" Texbox
* Abilities:
* 1. Navigate with mouse
* 2. Navigate with keybard
* 3. Delete and change text
* Length of entering text is restricted by length of Texbox
*/




class TextBox : public Control
{
protected:
	string value;
	int cursorPosition;
	int logicalPosition = 0;
	int panelLeft;
	int panelTop;
	int presscount;

public:
	TextBox();
	TextBox(short _left, short _top, short _width, short _height);
	~TextBox();
	void setValue(string _value) { this->value = _value; logicalPosition = value.size();  };
	string getValue() { return this->value; }
	void setCursorPosition(int _cp) { this->cursorPosition = _cp; };
	int getCursorPosition() { return this->cursorPosition; }
	bool canGetFocus() { return true; };
	void focusOn() {
		OutputDebugStringW(L"focus on TextBox\n");

		graphic.moveTo(left + logicalPosition, top );
		graphic.setCursorVisibility(true);
	};
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	// bool canGetFocus();
};
