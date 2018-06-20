#include "Control.h"

class TextBox : public Control
{
protected:
	string value;
	int cursorPosition;
	//Graphics gg;
public:
	TextBox();
	TextBox(short _left, short _top, short _width, short _height);
	~TextBox();
	void setValue(string _value) { this->value = _value; };
	string getValue() { return this->value; }

	void setCursorPosition(int _cp) { this->cursorPosition = _cp; };
	int getCursorPosition() { return this->cursorPosition; }
	bool canGetFocus() { return true; };
	void focusOn() {
		//gg.moveTo(this->getLeft() + 2 , this->getTop() + 2);
		//gg.setCursorVisibility(true);
	}
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(int keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);

};
