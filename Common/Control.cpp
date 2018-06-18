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
	/*
	if (this->bt != NULL)
	{ 
	BorderType* border = this->getBorderType();
	border->drawBorder(g , this->getLeft()+x+1, this->getTop()+1, this->getWidth()+2, this->getHeight()+2);
	}
	*/
}