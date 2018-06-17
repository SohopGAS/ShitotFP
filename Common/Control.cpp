#include "Control.h"

Control* Control::static_control = NULL;

Control::Control() {}

Control::~Control()
{
}

void Control::draw(Graphics& g, int x, int y, size_t z) {
	bt->drawBorder(x,y,this->getWidth,this->getHeight);

}