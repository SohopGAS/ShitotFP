#include "Control.h"

class TextBox :public Control
{
protected:
	string _value;
	int _cursorPosition;

public:
	TextBox();
	void setValue(string str) { this->_value = str; };
	void draw(Graphics& g, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	~TextBox();
};

