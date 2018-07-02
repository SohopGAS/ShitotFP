#include "Panel.h"

void Panel::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugStringW(L"Panel::mousePressed\n");
	int i;
	for (i = 0; i < controls.size(); i++) {
		if( isInside(x,y,controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight() ) )
		{
			OutputDebugStringW(L"Panel::mousePressed is inside\n");
			controls[i]->mousePressed(x, y, isLeft);
		}
	}
}

void Panel::Add(Control* control) {
	controls.push_back(control);
}

void Panel::draw(Graphics& g, short x, short y, size_t z) {
	
		Control::draw(g, x, y, z);
		for(Control* c : this->controls)
			c->draw(g, x, y, z);
	
}

void Panel::getAllControls(vector<Control*>* controls_)
{
		for (Control *c : this->controls) {
			controls_->push_back(c);
		}
	
}



