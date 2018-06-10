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

void Panel::draw(Graphics& g, int x, int y, size_t z) {
	int i;
	for (i = 0; i < controls.size() - 1; i++) {
		controls[i]->draw(g, x, y, z);
	}	
}
