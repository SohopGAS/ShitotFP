#include "Control.h"

class TextBox :public Control
{
protected:
	short width;
public:
	TextBox();

	void setWidth(short Width) { this->width = Width; }
	void draw(Graphics& g, int x, int y, size_t z);

	~TextBox();
};

