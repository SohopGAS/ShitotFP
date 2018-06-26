#include "NumericBox.h"






NumericBox::NumericBox()
{

	plus.setValue("+");
	minus.setValue("-");
	plus.setTop(getTop());
	plus.setLeft(getLeft());
	plus.setHeight(1);
	plus.setWidth(plus.getValue().size());
	//plus.setBorderType();
	plus.setColor(ColorType::Blue, ColorType::Red);

	minus.setTop(getTop());
	minus.setLeft(getLeft());
	minus.setHeight(1);
	minus.setWidth(plus.getValue().size());
	//plus.setBorderType();
	minus.setColor(ColorType::Blue, ColorType::Red);


	Add(&minus);
	Add(&plus);




	
	




}



void NumericBox::mousePressed(int x, int y, bool isLeft) {

	CLogger::GetLogger()->Log("mouse pressed numric");
	CLogger::GetLogger()->Log("COORD %d ,%d , %d ", x, y, left);
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {

		//for (MouseListener* listener : listeners) {
		//	listener->MousePressed(x, y, isLeft);
		//}

	}
}