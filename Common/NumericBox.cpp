#include "NumericBox.h"

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi


NumericBox::NumericBox()
{
}



void NumericBox::mousePressed(int x, int y, bool isLeft) {
	
	OutputDebugStringW(L"Numric Box :: mousePressed\n");
	std::string::size_type sz, sz2;
	int result_change;
	int i;
	for (i = 0; i < controls.size(); i++) {
		OutputDebugStringW(L"Numric Box :: for loop \n");/*if(controls[i].plus_ == true)
				{
					OutputDebugStringW(L"on click\n");
				}*/

		if (i == 0) {

			if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
			{
				Button* bt = (Button *)controls[i];
				int j = 0;
				string string_change1;
				string max_value;
				int string_change2;
				//Label* lb = (Label *)controls[i + 1];
				bt->listeners[0]->MousePressed(x, y, isLeft);

				//Label * lb = (Label *)controls[i];
				//result_change =stoi(getva, &sz);
				string_change2 = stoi(this->label_value.getValue(), &sz);
				string_change2 = string_change2 + 1;
				string_change1 = std::to_string(string_change2);
				max_value = std::to_string(this->maxVal);
				if (this->maxVal >= string_change2){
					this->label_value.setValue(string_change1);
				}
				else this->label_value.setValue(max_value);
				
				

				//Button* bt_minus = (Button *)controls[2];

				//string string_change_minus1;
				//int string_change2_minus;
				////Label* lb = (Label *)controls[i + 1];
				//bt_minus->listeners[2]->MousePressed(x, y, isLeft);

				////Label * lb = (Label *)controls[i];
				////result_change =stoi(getva, &sz);
				//string_change2_minus = stoi(this->label_value.getValue(), &sz2);
				//string_change2_minus = string_change2_minus -1;
				//string_change1 = std::to_string(string_change2_minus);
				//this->label_value.setValue(string_change_minus1);





			//if ( bt->listeners[0]->MousePressed(x, y, isLeft) == true) {
			//	this->l
			//	//label ++
			//}
				OutputDebugStringW(L"bla bla\n");
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
				//Label* lb = (Label *)controls[i + 1];
				bt_minus->listeners[0]->MousePressed(x, y, isLeft);

				//Label * lb = (Label *)controls[i];
				//result_change =stoi(getva, &sz);
				string_change2_minus = stoi(this->label_value.getValue(), &sz2);
				string_change2_minus = string_change2_minus - 1;
				string_change1_minus = std::to_string(string_change2_minus);
				min_value = std::to_string(this->minVal);
				if (this->minVal >= string_change2_minus) {
				 this->label_value.setValue(min_value);
				}
				
				else this->label_value.setValue(string_change1_minus);

				//Button* bt_minus = (Button *)controls[2];

				//string string_change_minus1;
				//int string_change2_minus;
				////Label* lb = (Label *)controls[i + 1];
				//bt_minus->listeners[2]->MousePressed(x, y, isLeft);

				////Label * lb = (Label *)controls[i];
				////result_change =stoi(getva, &sz);
				//string_change2_minus = stoi(this->label_value.getValue(), &sz2);
				//string_change2_minus = string_change2_minus -1;
				//string_change1 = std::to_string(string_change2_minus);
				//this->label_value.setValue(string_change_minus1);





				//if ( bt->listeners[0]->MousePressed(x, y, isLeft) == true) {
				//	this->l
				//	//label ++
				//}
				OutputDebugStringW(L"bla bla\n");
			}
		}

	}


	}



//void NumericBox::onClikck_plus()
//{
//	if (this->Add.plus_ = true)
//	{
//		this->Add
//	}
//}

void NumericBox::init()
{

	plus.setValue("+");
	minus.setValue("-");
	plus.setTop( getTop()+(1));
	plus.setLeft( getLeft()+1 );
	//plus.setHeight(2);
	//plus.setWidth(2);
	plus.setWidth(plus.getValue().size());
	
	BorderType* border_plus = SingleLineBorder::getinstance();
	plus.setBorderType(border_plus);
	plus.setColor(ColorType::Black, ColorType::Orange);

	

	label_value.setValue("1");
	label_value.setLeft( plus.getLeft() +5);
	label_value.setTop( getTop()+1 );

	label_value.setColor(ColorType::Black, ColorType::Orange);


	minus.setTop(getTop()+1);
	minus.setLeft( plus.getLeft() +9);
	minus.setWidth(minus.getValue().size());
	//plus.setBorderType();
	minus.setColor(ColorType::Black, ColorType::Orange);
	BorderType* border_minus = SingleLineBorder::getinstance();
	minus.setBorderType(border_minus);

	
	//getLeft()  minus.getLeft() +1 
	//  need to place elsewhere 
	setWidth(12);
	setHeight(3);

	plus.AddListener(this->plus_);
	minus.AddListener(this->minus_);



	Add(&plus);
	Add(&label_value);
	Add(&minus);

}