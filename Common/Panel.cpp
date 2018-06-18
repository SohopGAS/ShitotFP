#include "Panel.h"



Panel::Panel()
{
}


Panel::~Panel()
{

}

void Panel::Add(Control* control) {
	controls.push_back(control);
}

void Panel::draw(Graphics& g, short x, short y, size_t z) {
	
		Control::draw(g, x, y, z);
		for(Control* c : this->controls)
			c->draw(g, x, y, z);
	
}
