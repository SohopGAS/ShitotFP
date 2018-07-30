#include "../Common/RadioBox.h"

// implements draw
void RadioBox::draw(Graphics &g, short left, short top, size_t layer)
{
	// draw border
	Control::draw(g, this->getLeft(), this->getTop(), layer);

	int vector_size = controls.size();

	g.moveTo(this->getLeft(), this->getTop());

	for (int i = 0; i < vector_size; i++) {
		g.setBackground(this->bg);
		g.setForeground(this->fg);
		if (i == logicalPosition) {
			// check this loop again  
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

// selectedItem function - return the boolean represent the index status
boolean RadioBox::selectedItem(int index) {
	if (index < this->controls.size() && index >= 0) {
		logicalPosition = index;
		return true;
	}
	return false;
}

// selectedItem function - return the bool represent the index
void RadioBox::selectOption() {

	int i = 0;
	Label* l;
	Label* tmp_label;

	if ( ! optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = true;
		// Change string in Label. Based on logicalPosition.
		l = (Label*)controls[logicalPosition];		// Casting from vector controls Control* to Label*.
		l->setValue(l->getValue().replace(1, 1, "X"));

		for (; i < optionsSelected.size(); i++) {
			if (i != logicalPosition) {
				optionsSelected[i] = false;
				tmp_label = (Label*)controls[i];
				tmp_label->setValue(tmp_label->getValue().replace(1, 1, " ")  );
			}
		}
	}
	else {
		// if true - press again on selcted option. Do nothing if is there.
	}
}

// clearSelection function reset logicalPosition to 0
boolean RadioBox::clearSelection()
{
	for (bool op : optionsSelected) {
		op = false;
	}
	logicalPosition = 0;
	return true;
}

// implement mousePressed - check where pressed and update
void RadioBox::mousePressed(int x, int y, bool isLeft) 
{
	int i;
	for (i = 0; i < controls.size(); i++) {
		if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()) )
		{
			logicalPosition = i;
			RadioBox::selectOption();
		}
	}
}


// implement keyDown 
void RadioBox::keyDown(WORD code, char charecter) 
{
// check which key pressed
	switch (code) {
	case VK_UP:
		if (logicalPosition >= 1) {										// if Up pressed change logicalPosiotion
			logicalPosition--;
		}
		else {
			logicalPosition = controls.size() - 1;
		}
		break;
	case VK_DOWN:														// if Down pressed change logicalPosiotion
		if (logicalPosition < controls.size() - 1)
			logicalPosition++;
		else
			logicalPosition = 0;
		break;
	case VK_RETURN:														// if Enter or Space pressed update
	case VK_SPACE:
		RadioBox::selectOption();
		break;
	}
}

// setList input - Vector of string represent label value, Square_shape add to every string
void RadioBox::setList(vector<string> ListOfStrings, string Square_shape) 
{
	int size = ListOfStrings.size();
	int maxsize = 0;
	int ezer = 0;
	int heCalc = 1;

	for (int i = 0; i < size; i++) {
		ListOfStrings[i].insert(0, Square_shape);
		if (maxsize < ListOfStrings[i].size() - 1)
			maxsize = ListOfStrings[i].size() - 1;
	}

	this->setWidth(maxsize + 1);
	this->setHeight(ListOfStrings.size());

	for (int i = 0; i < size; i++) {
		ezer = maxsize - ListOfStrings[i].size() + 1;
		if (ListOfStrings[i].size() - 1 < maxsize)
			for (int j = 0; j < ezer; j++) {
				ListOfStrings[i].insert(ListOfStrings[i].size(), " ");
			}
	}

	// Create label and puts in the list (controls).
	for (int i = 0; i < size; i++) {
		Control* tmp = (Control*)new Label(ListOfStrings[i]);
		tmp->setTop(this->getTop()+i);
		tmp->setLeft(this->getLeft() );
		tmp->setWidth(maxsize);
		tmp->setHeight(1);
		add(tmp);
	}

	optionsSelected = vector<bool>(ListOfStrings.size());
	this->setHeight(controls.size());
	this->setWidth(maxsize + 1);

}
