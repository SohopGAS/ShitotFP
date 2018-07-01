#include "../Common/RadioBox.h"


void RadioBox::draw(Graphics &g, short left, short top, size_t layer)
{
	Control::draw(g, this->getLeft(), this->getTop(), layer);

	int vector_size = controls.size();
	g.moveTo(this->getLeft(), this->getTop());

	for (int i = 0; i < vector_size; i++) {
		g.setBackground(this->bg);
		g.setForeground(this->fg);
		if (i == logicalPosition) {
			
			
			// check this loop again  ---- 
			if (Control::getFocus() == this) {
				g.setBackground(ColorType::Red);
			}



			Label* lb = (Label*) controls[i];
			g.write( lb->getValue()  );
			g.moveTo(this->getLeft(), this->getTop() + i + 1);

		}
		else {
			g.setBackground(this->bg);
			g.setForeground(this->fg);
			Label* lb = (Label*)controls[i];
			g.write( lb->getValue() );
			g.moveTo(this->getLeft(), this->getTop() + i + 1);
		}

	}
}


boolean RadioBox::SelectedItem(int index) {
	if (index < this->controls.size() && index >= 0) {
		logicalPosition = index;
		return true;
	}
	return false;
}

void RadioBox::selectOption() {
	OutputDebugStringW(L" RadioBox::selectOption \n");

	if ( ! optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = true;
		OutputDebugStringW(L"  optionsSelected[logicalPosition] =           true        ;\n");
		

		// change string in Label    Based on logicalPosition
		Label* l = (Label*)controls[logicalPosition];					// cast from vector controls Control* to Label*   
		
		l->setValue( l->getValue().replace(1, 1, "X") );
		
		int i = 0;		
		for (; i < optionsSelected.size();i++ ) {
			if ( i !=  logicalPosition) {
				optionsSelected[i] = false;
				Label* tmp_label = (Label*)controls[i];
				tmp_label->setValue(  tmp_label->getValue().replace(1, 1, " ")  );
			}
		}
	}
	else {
		//		if true -- press again on selcted option   ---   do nothing if is there 
		OutputDebugStringW(L"  optionsSelected[logicalPosition] =      true -- not change     ;\n");
	}

}


boolean RadioBox::ClearSelection()
{
	for (bool op : optionsSelected) {
		op = false;
	}
	logicalPosition = 0;
	return true;
}

void RadioBox::mousePressed(int x, int y, bool isLeft) {
	OutputDebugStringW(L"RadioBox :: mousePressed\n");
	
	int i;
	for (i = 0; i < controls.size(); i++) {
		OutputDebugStringW(L"radiobox :: for loop \n");
		if (  isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight())  )
		{
			
			OutputDebugStringW(L"Panel::mousePressed is inside\n");

			logicalPosition = i;
			RadioBox::selectOption();
		}

	}


}

void RadioBox::keyDown(WORD code, char charecter) {

	OutputDebugStringW(L"RadioBox :: keyDown\n");

	switch (code) {
	case VK_UP:
		OutputDebugStringW(L"RadioBox :: up\n");
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		else {
			logicalPosition = controls.size() - 1;
		}
		break;
	case VK_DOWN:
		OutputDebugStringW(L"RadioBox :: down \n");
		if (logicalPosition < controls.size() - 1) {
			logicalPosition++;
		}
		else {
			logicalPosition = 0;
		}
		break;
	case VK_RETURN:
		RadioBox::selectOption();
		break;
	case VK_SPACE:
		RadioBox::selectOption();
		break;
	case VK_TAB:
		logicalPosition++;
		if (logicalPosition > controls.size()) {
			/// go to next component	
		}
		break;

	}
}

void RadioBox::init(){
	
	// insert to label value ( ) 
	string s = "( ) radio box ";
	
	lab1.setValue(s);
	lab1.setTop(this->getTop() );
	lab1.setLeft(this->getLeft() );
	lab1.setWidth(10);
	lab1.setColor(ColorType::Black, ColorType::Orange);

	lab2.setValue(s);
	lab2.setTop(this->getTop() + 1);
	lab2.setLeft(this->getLeft());
	lab2.setColor(ColorType::Black, ColorType::Orange);
	lab2.setWidth(10);

	lab3.setValue(s);
	lab3.setTop(this->getTop() + 2);
	lab3.setLeft(this->getLeft());
	lab3.setColor(ColorType::Black, ColorType::Orange);
	lab3.setWidth(10);

	Add(&lab1);
	Add(&lab2);
	Add(&lab3);

	this->setHeight(controls.size() );
	this->setWidth(lab1.getValue().size() + 1);

	optionsSelected = vector<bool>(controls.size());
}