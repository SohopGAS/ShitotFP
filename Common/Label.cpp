#include <iostream>

#include "Label.h"
#include "Control.h"
#include "Logger.h"

// constrctor parmeter
Label::Label(string value) : Control(), value(value) {};


// set for the label
void Label::setValue(string value)
{
	this->value = value;
}


// implement draw 
void Label::draw(Graphics& g, short x, short y, size_t z)
{
	// draw boarder
	Control::draw(g, x,y, z);

	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
}
