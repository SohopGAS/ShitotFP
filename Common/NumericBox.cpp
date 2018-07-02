#include "NumericBox.h"

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi


NumericBox::NumericBox()
{
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {

	std::string::size_type sz, sz2;
	int result_change;
	int i;
	for (i = 0; i < controls.size(); i++) {
		if (i == 0) {
			if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
			{


				Button* bt = (Button *)controls[i];
				int j = 0;
				string string_change1;
				string max_value;
				int string_change2;
				bt->mousePressed(x,y,isLeft);
				if (plus_.addNum) {
					string_change2 = stoi(this->label_value.getValue(), &sz);
					string_change2 = string_change2 + 1;
					string_change1 = std::to_string(string_change2);
					max_value = std::to_string(this->maxVal);
					if (this->maxVal >= string_change2) {
						this->label_value.setValue(string_change1);
					}
					else this->label_value.setValue(max_value);
				}
			}
		}

		else if (i == 2) {
			if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
			{
				Button* bt_minus = (Button *)controls[i];
				int j = 0;
				string min_value;
				string string_change1_minus;
				int string_change2_minus;
				
				bt_minus->mousePressed(x, y, isLeft);

				if (minus_.subNum) {
					string_change2_minus = stoi(this->label_value.getValue(), &sz2);
					string_change2_minus = string_change2_minus - 1;
					string_change1_minus = std::to_string(string_change2_minus);
					min_value = std::to_string(this->minVal);
					if (this->minVal >= string_change2_minus) {
						this->label_value.setValue(min_value);
					}

					else this->label_value.setValue(string_change1_minus);

				}
			}
		}
	}
}

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

	label_value.setValue("1");
	label_value.setLeft( plus.getLeft() + 5 );
	label_value.setTop( getTop() + 1 );

	label_value.setColor(ColorType::Black, ColorType::Orange);

	minus.setTop( getTop() + 1 );
	minus.setLeft( plus.getLeft() + 9 );
	minus.setWidth( minus.getValue().size() );
	
	minus.setColor(ColorType::Black, ColorType::Orange);
	BorderType* border_minus = SingleLineBorder::getinstance();
	minus.setBorderType(border_minus);

	setWidth(12);
	setHeight(3);

	plus.AddListener(this->plus_);
	minus.AddListener(this->minus_);

	Add(&plus);
	Add(&label_value);
	Add(&minus);
}