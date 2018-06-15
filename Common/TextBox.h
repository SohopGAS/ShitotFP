#include "Control.h"

class TextBox :public Control
{
protected:
	string value;
	int cursorPosition;

public:
	TextBox();
	void setValue(string _value) { this->value = _value; };
	string getValue() { return this->value; }

	void setCursorPosition(int _cp) { this->cursorPosition = _cp; };
	int getCursorPosition() { return this->cursorPosition; }

	void draw(Graphics& g, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	~TextBox();
};
