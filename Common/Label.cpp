#include "Label.h"
#include "Control.h"
#include "Logger.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {};


void Label::setValue(string value)
{
	this->value = value;
}


void Label::draw(Graphics& g, short x, short y, size_t z)
{
<<<<<<< HEAD
	// CLogger::GetLogger()->Log("draw label");
=======
	Control::draw(g, x,y, z);
	//CLogger::GetLogger()->Log("draw label");

>>>>>>> master
	g.setBackground(this->bg);
	g.setForeground(this->fg);
	g.moveTo(getLeft(), getTop());
	if (!z)
		g.write(value);
	
}

void Label::keyDown(WORD keyCode, char charecter) {

}