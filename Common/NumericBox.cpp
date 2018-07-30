#include <iostream>
#include <string>
#include "NumericBox.h"


// constrctor 
NumericBox::NumericBox()
{}

// implement mousePressed - check where pressed and update logicalPosiiton
void NumericBox::mousePressed(int x, int y, bool isLeft) {
	std::string::size_type sz, sz2;
	int change2, change2Minus;
	int i;
	Button* bt;
	Button* btMinus;
	string change1, maxValue, minValue, change1Minus;

	for (i = 0; i < controls.size(); i++) {
		if (i == 0) {
			if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
			{
				bt = (Button *)controls[i];
				bt->mousePressed(x,y,isLeft);
				if (plus_.addNum) {
					change2 = stoi(this->labelValue.getValue(), &sz);
					change2 = change2 + 1;
					change1 = std::to_string(change2);
					maxValue = std::to_string(this->maxVal);
					if (this->maxVal >= change2) {
						this->labelValue.setValue(change1);
					}
					else this->labelValue.setValue(maxValue);
				}
			}
		}

		else if (i == 2) {
			if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
			{
				btMinus = (Button *)controls[i];
				btMinus->mousePressed(x, y, isLeft);
				if (minus_.subNum) {
					change2Minus = stoi(this->labelValue.getValue(), &sz2);
					change2Minus = change2Minus - 1;
					change1Minus = std::to_string(change2Minus);
					minValue = std::to_string(this->minVal);
					if (this->minVal >= change2Minus)
						this->labelValue.setValue(minValue);
					else
						this->labelValue.setValue(change1Minus);
				}
			}
		}
	}
}

// init function 
void NumericBox::init()
{
	plus.setValue("+");
	minus.setValue("-");
	plus.setTop( getTop() +  1 );
	plus.setLeft( getLeft() + 1);
	plus.setWidth( plus.getValue().size() );

	BorderType* border_plus = SingleLineBorder::getinstance();
	plus.setBorderType(border_plus);
	plus.setColor(ColorType::Black, ColorType::Orange);

	labelValue.setValue("1");
	labelValue.setLeft( plus.getLeft() + 5 );
	labelValue.setTop( getTop() + 1 );

	labelValue.setColor(ColorType::Black, ColorType::Orange);

	minus.setTop( getTop() + 1 );
	minus.setLeft( plus.getLeft() + 9 );
	minus.setWidth( minus.getValue().size() );

	minus.setColor(ColorType::Black, ColorType::Orange);
	BorderType* border_minus = SingleLineBorder::getinstance();
	minus.setBorderType(border_minus);

	setWidth(12);
	setHeight(3);

	plus.addListener(this->plus_);
	minus.addListener(this->minus_);

	add(&plus);
	add(&labelValue);
	add(&minus);
}
