#include "Control.h"

Control* Control::static_control = NULL;


Control::~Control()
{
}

Control::Control():bt(NULL)
{
}

Control::Control(Graphics & g, short x, short y, short width, short height) : bt(NULL)
{
}

void Control::draw(Graphics& g, short x, short y, size_t z) {
	
	if (this->bt != NULL)
	{ 
	BorderType* border = this->getBorderType();
	border->drawBorder(g , getLeft()-1, getTop()-1, getWidth()+2, getHeight()+2);
	}
	
}