#include "../Common/CheckList.h"
#include "../Common/Label.h"

void CheckList::keyDown(WORD code, char chr) {
	// check which key pressed 
	switch (code) {
	case VK_UP:													// for UP pressed, update logicalPosition var 
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		else {
			logicalPosition = controls.size() - 1;
		}
		break;
	case VK_DOWN:												// for Down pressed, update logicalPosition var
		if (logicalPosition < controls.size() - 1) {
			logicalPosition++;
		}
		else {
			logicalPosition = 0;
		}
		break;
	case VK_RETURN:												// for Enter or Space  pressed, update the list
	case VK_SPACE:
		CheckList::selectOption();
		break;
	}
}

// init the list 
// input var is Vector of string- represent the value for label
void CheckList::setList(vector<string> ListOfStrings) {
	string Square_shape = "[ ] ";
	int size = ListOfStrings.size();
	int maxsize = 0;
	int ezer = 0;
	int heCalc = 1;
	
	// add sign for the label string
	for (int i = 0; i < size; i++) {
		ListOfStrings[i].insert(0, Square_shape);
		if (maxsize < ListOfStrings[i].size() - 1)
			maxsize = ListOfStrings[i].size() - 1;
	}

	// update the width and height
	this->setWidth(maxsize + 1);
	this->setHeight(ListOfStrings.size());

	// add spaces to make full list
	for (int i = 0; i < size; i++) {
		ezer = maxsize - ListOfStrings[i].size() + 1;
		if (ListOfStrings[i].size() - 1 < maxsize)
			for (int j = 0; j < ezer; j++) {
				ListOfStrings[i].insert(ListOfStrings[i].size(), " ");
			}
	}

	// create label and puts in the list
	for (int i = 0; i < size; i++) {
		Control* tmp = (Control*)new Label(ListOfStrings[i]);
		tmp->setTop(this->getTop() + i);
		tmp->setLeft(this->getLeft());
		tmp->setWidth(maxsize);
		tmp->setHeight(1);
		add(tmp);
	}

	// init vector of bool for the selected represntion 
	optionsSelected = vector<bool>(ListOfStrings.size());
	this->setHeight(controls.size());
	this->setWidth(maxsize + 1);

}

// choose index value and update
void CheckList::SelectIndex(size_t index) {
	logicalPosition = index;
	selectOption();
}

// deselect the input index - if logicalPosition == index change the logicalPosition to 0 - update list
void CheckList::DeselectIndex(size_t index) {
	if (logicalPosition == index) {
		logicalPosition = 0;
	}
	selectOption();
}

// mousePressed check where pressed and update logicalPosiotion and Update
void CheckList::mousePressed(int x, int y, bool ifFirstButton) {
	int i;

	for (i = 0; i < controls.size(); i++) {
		if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()))
		{
			logicalPosition = i;
			CheckList::selectOption();
		}
	}
}

// update functino 
void  CheckList::selectOption() {
	if (optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = false;
		graphic.moveTo(this->getLeft() + 2, this->getTop() + logicalPosition + 1);
		Label* tmp_label = (Label*)controls[logicalPosition];
		tmp_label->setValue(tmp_label->getValue().replace(1, 1, " "));
	}
	else {
		graphic.moveTo(this->getLeft() + 2,this->getTop() + logicalPosition + 1);
		Label* tmp_label = (Label*)controls[logicalPosition];
		tmp_label->setValue(tmp_label->getValue().replace(1, 1, "X"));
		optionsSelected[logicalPosition] = true;
	}
}

// GetSelectedIndexs function return the choosen label- go over the vector optionsSelected and search for True - return that varible 
vector<size_t> CheckList::GetSelectedIndexs() {
	vector<size_t> result;

	for (int i = 0; i < optionsSelected.size(); i++) {
		if (optionsSelected[i] == true) {
			result.push_back(i);
		}
	}
	return result;
}

// draw implemnt
void CheckList::draw(Graphics &g, short left, short top, size_t layer)
{	
	// draw border	
	Control::draw(g, this->getLeft(), this->getTop() , layer);

	int vector_size = controls.size();
	g.moveTo(this->getLeft(), this->getTop());

	for (int i = 0; i < vector_size; i++) {
		g.setBackground(this->bg);
		g.setForeground(this->fg);
		if (i == logicalPosition) {
			// mark background
			if (Control::getFocus() == this) {
				g.setBackground(ColorType::Red);
			}
			Label* lb = (Label*)controls[i];
			g.write(lb->getValue());
			g.moveTo(this->getLeft(), this->getTop() + i + 1);
		}
		else {
			g.setBackground(this->bg);
			g.setForeground(this->fg);
			Label* lb = (Label*)controls[i];
			g.write(lb->getValue());
			g.moveTo(this->getLeft(), this->getTop() + i + 1);
		}
	}
}

// indexInVector function return the bool in the selected option
bool CheckList::indexInVector() {
	return optionsSelected[logicalPosition];
}


// focusOn function move the cursor 
void CheckList::focusOn() {
	graphic.moveTo(left + 1, top + logicalPosition);
};

// constrctor
CheckList::CheckList()
{}

// destrctor
CheckList::~CheckList()
{}
