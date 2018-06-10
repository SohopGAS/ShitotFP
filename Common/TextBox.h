#include "Control.h"

class TextBox :public Control
{
protected:
	short width;
public:
	TextBox();

	void setWidth(short Width) { this->width = Width; }

	~TextBox();
};

