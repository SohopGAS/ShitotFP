#include "NumericBox.h"


NumericBox::NumericBox(int minVal, int maxVal) 
{
	this->minVal = minVal;
	this->maxVal = maxVal;
	this->setWidth(6);


	this->plus.setValue("+");
	this->plus.setLeft(1);
	this->plus.setTop(2);
	
	this->minus.setValue("-");
	this->label_value.setLeft(3);
	this->label_value.setTop(2);
	this->minus.setLeft(5);
	this->minus.setTop(2);
	this->label_value.setValue(0);
}

void NumericBox::draw(Graphics& g, int x, int y, size_t z) {
	//Control::draw(g, x, y, z);
	minus.draw(g, x , y, z);
	label_value.draw(g , x, y, z);
	plus.draw(g, x, y, z);
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {

}