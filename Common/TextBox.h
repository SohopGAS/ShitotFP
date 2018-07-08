#include "Control.h"

class TextBox : public Control
{
protected:
	// variable
	string value;
	int logicalPosition = 0;

	
public:
	TextBox();
	TextBox(short _left, short _top, short _width, short _height);
	~TextBox();

	// set value string 
	void setValue(string _value) { this->value = _value; logicalPosition = value.size();  };
	// get value string
	string getValue() { return this->value; }


	// function implemnted 
	bool canGetFocus() { return true; };
	void focusOn(); 
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
};
