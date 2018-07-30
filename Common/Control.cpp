#include "Control.h"

// init static_control pointer with null
Control* Control::static_control = NULL;
DWORD output = STD_OUTPUT_HANDLE;

// destrctor
Control::~Control()
{
}


// constrctor - bt get null to make avoid failier
Control::Control():bt(NULL)
{
}

// constrctor prameter 
Control::Control(Graphics & g, short x, short y, short width, short height) : bt(NULL)
{
	graphic = g;
	left = x;
	top = y;
	width = width;
	height = height;
}


// draw implement 
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