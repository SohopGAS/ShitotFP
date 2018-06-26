#include "RadioBox.h"



void RadioBox::draw(Graphics& g, short x, short y, size_t z) {

}

RadioBox::RadioBox()
{
	Label l1;
	Label l2;
	Label l3;

	string s = "radio box :";
	l1.setValue(s);
	l2.setValue(s);
	l3.setValue(s);

	Add(&l1);
	Add(&l2);
	Add(&l3);
};