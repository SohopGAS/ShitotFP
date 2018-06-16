#include "Control.h"
#include "EventEngine.h"
Control* Control::static_control = NULL;

Control::Control() {}

Control::Control(short _left, short _top, short _width, short _height)
{
}

Control::~Control()
{
}

void Control::setFocus(Control & control)
{
	static_control = &control;
}

Control * Control::getFocus()
{
	return static_control;
}

void Control::draw(Graphics& g, int x, int y, size_t z) {
	// TODO: add drow border 
}

void Control::mousePressed(int x, int y, bool isLeft)
{

	if (isInside(x, y, this->left, this->top, this->width, this->height))
	{
		const vector<Control*>* temp = this->controls;
		for (Control* c : *controls) {
			if (isInside(x, y, c->left, c->top, c->width, c->height)) {
				setFocus(*c);
			}
		}
	}
}

void Control::keyDown(int keyCode, char charecter)
{
}

vector<Control*>* Control::getAllControls(vector<Control*>* controls)
{
	if (hasChildren == TRUE && this->controls != NULL) {
		if (controls == NULL) {
			return;
		}
		const vector<Control*>* temp = this->controls;
		for (Control* c : *temp) {
			controls->push_back(c);
		}
	}
}

void Control::setAllControls(vector<Control*>* controls)
{
	if (controls == NULL) {
		return;
	}

	this->hasChildren = TRUE;
	const vector<Control*>* temp = controls;
	for (Control* c : *temp) {
		this->controls->push_back(c);
	}

}

void Control::addControl(Control* newC)
{
	if (newC == NULL) {
		return;
	}
	if (this->hasChildren == NULL) {
		this->hasChildren = TRUE;
		this->controls->push_back(newC);
	}
	else {
		this->controls->push_back(newC);
	}
}
