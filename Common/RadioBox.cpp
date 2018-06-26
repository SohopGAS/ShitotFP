#include "RadioBox.h"

boolean RadioBox::SelectedItem(int index)
{
	return true;
}


boolean RadioBox::ClearSelection()
{
	return true;
}

void RadioBox::init(){

	string s = "radio box: ";
	lab1.setValue(s);
	lab1.setTop(this->getTop() );
	lab1.setLeft(this->getLeft());
	lab1.setColor(ColorType::Black, ColorType::Orange);

	lab2.setValue(s);
	lab2.setTop(this->getTop() + 1);
	lab2.setLeft(this->getLeft());
	lab2.setColor(ColorType::Black, ColorType::Orange);

	lab3.setValue(s);
	lab3.setTop(this->getTop() + 2);
	lab3.setLeft(this->getLeft());
	lab3.setColor(ColorType::Black, ColorType::Orange);

	Add(&lab1);
	Add(&lab2);
	Add(&lab3);

	this->setHeight(controls.size() );
	this->setWidth(lab1.getValue().size() + 1);
}