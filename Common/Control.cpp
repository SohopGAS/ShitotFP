#include "Control.h"

Control* Control::static_control = NULL;
DWORD output = STD_OUTPUT_HANDLE;

Control::~Control()
{
}

Control::Control():bt(NULL)
{
	hasChildren = false;
}

Control::Control(Graphics & g, short x, short y, short width, short height) : bt(NULL)
{
	graphic = g;
	left = x;
	top = y;
	width = width;
	height = height;
	hasChildren = false;
}

void Control::draw(Graphics& g, short x, short y, size_t z) {
	
	if (this->bt != NULL)
	{ 
	BorderType* border = this->getBorderType();
	int t = getTop();
	int l = getLeft();
	if (t > 0) t--;
	if (l > 0)l--;
	border->drawBorder(g , l, t, getWidth()+2, getHeight()+2);
	}
	
}