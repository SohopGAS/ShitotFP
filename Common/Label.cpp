#include "Label.h"
#include "Control.h"

#include <iostream>

Label::Label(string value) : Control(), value(value) {};


void Label::setValue(string value)
{
	this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
}
