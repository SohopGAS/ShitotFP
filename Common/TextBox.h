#include "Control.h"

<<<<<<< HEAD
class TextBox :public Control
=======
class TextBox : public Control
>>>>>>> master
{
protected:
	string value;
	int cursorPosition;

public:
	TextBox();
<<<<<<< HEAD
=======
	TextBox(short _left, short _top, short _width, short _height);
	~TextBox();
>>>>>>> master
	void setValue(string _value) { this->value = _value; };
	string getValue() { return this->value; }

	void setCursorPosition(int _cp) { this->cursorPosition = _cp; };
	int getCursorPosition() { return this->cursorPosition; }

	void draw(Graphics& g, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
<<<<<<< HEAD
	~TextBox();
=======

>>>>>>> master
};
