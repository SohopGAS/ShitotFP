#include "NumericBox.h"






NumericBox::NumericBox(int minVal, int maxVal)
{
	minVal = minVal;
	maxVal = maxVal;

	
	string Button_plus("+");
	string Button_minus("-");

	
	plus.setValue(Button_plus);
	plus.setTop(7);
	plus.setLeft(2);
	plus.setColor(ColorType::Red, ColorType::Green);
	

	minus.setValue(Button_plus);
	minus.setTop(11);
	minus.setLeft(2);
	minus.setColor(ColorType::Red, ColorType::Green);


	



	
	




}

void NumericBox::draw(Graphics& g, short x, short y, size_t z) {

  

}

void NumericBox::mousePressed(int x, int y, bool isLeft) {

}