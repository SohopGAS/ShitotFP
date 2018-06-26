#include "NumericBox.h"




NumericBox::NumericBox()
{	
}



void NumericBox::mousePressed(int x, int y, bool isLeft) {
	//CLogger::GetLogger()->Log("mouse pressed numric");
	//CLogger::GetLogger()->Log("COORD %d ,%d , %d ", x, y, left);
	if (isInside(x, y, getLeft(), getTop(), getWidth(), getHeight())) {

		//for (MouseListener* listener : listeners) {
		//	listener->MousePressed(x, y, isLeft);
		//}

	}
}

void NumericBox::init()
{

	plus.setValue("+");
	minus.setValue("-");
	plus.setTop( getTop() );
	plus.setLeft( getLeft() );

	plus.setWidth(plus.getValue().size());
	//plus.setBorderType();
	plus.setColor(ColorType::Black, ColorType::Orange);

	label_value.setValue("1");
	label_value.setLeft( plus.getLeft() +2 );
	label_value.setTop( getTop() );

	label_value.setColor(ColorType::Black, ColorType::Orange);


	minus.setTop(getTop());
	minus.setLeft( label_value.getLeft()+2 );
	minus.setWidth(minus.getValue().size());
	//plus.setBorderType();
	minus.setColor(ColorType::Black, ColorType::Orange);

	
	//getLeft()  minus.getLeft() +1 
	//  need to place elsewhere 
	setWidth(5);
	setHeight(1);


	Add(&minus);
	Add(&label_value);
	Add(&plus);

}