#include <iostream>

#include "Label.h"
#include "Control.h"
#include "Logger.h"

Label::Label(string value) : Control(), value(value) {};

void Label::setValue(string value)
{
	this->value = value;
}

void Label::draw(Graphics& g, short x, short y, size_t z)
{
	Control::draw(g, x,y, z);

	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
}
