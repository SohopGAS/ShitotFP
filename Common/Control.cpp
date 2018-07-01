#include "Control.h"

// Global Variables !
Control* Control::static_control = NULL;
DWORD output = STD_OUTPUT_HANDLE;

<<<<<<< HEAD
// Implemants methods:
Control::Control() : bt(NULL)
{

};

Control::Control(Graphics & g, short x, short y, short width, short height) : bt(NULL)
{
	graphic = g;
	left = x;
	top = y;
	width = width;
	height = height;
};

Control::~Control()
{

};

void Control::draw(Graphics& g, short x, short y, size_t z)
{
	if (this->bt != NULL)
	{
		BorderType* border = this->getBorderType();
		int t = getTop();
		int l = getLeft();
		if (t > 0)
			t--;
		if (l > 0)
			l--;
		border->drawBorder(g , l, t, getWidth()+2, getHeight()+2);
	}

}

void Control::setFocus(Control& control)
{
	Control::static_control = &control;
	if (static_control == nullptr)
	{
		cerr << "fml"<<endl;
		exit(-1);
	}
	// Control::static_control->focusOn();
};
=======
Control::Control() {
  setLeft(0);
  setTop(0);
  setWidth(0);
  setHeight(0);
  setBackground(ColorType::White);
  setForeground(ColorType::Black);
};

Control::~Control() {

};

void Control::draw(Graphics& g, int x, int y, size_t z) {
	// TODO: add draw border
}
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
