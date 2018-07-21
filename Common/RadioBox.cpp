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

	OutputDebugStringW(L" RadioBox::SelectedItem\n");

	if (index < this->controls.size() && index >= 0) {
		logicalPosition = index;
		return true;
	}
	return false;
}

void RadioBox::selectOption() {

	OutputDebugStringW(L" RadioBox::selectOption\n");

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


boolean RadioBox::ClearSelection()
{
	OutputDebugStringW(L"RadioBox::ClearSelection\n");

	for (bool op : optionsSelected) {
		op = false;
	}
	logicalPosition = 0;
	return true;
}

void RadioBox::mousePressed(int x, int y, bool isLeft) {

	OutputDebugStringW(L"RadioBox::mousePressed\n");

	int i;

	for (i = 0; i < controls.size(); i++) {
		OutputDebugStringW(L"radiobox::for loop \n");
		if (isInside(x, y, controls[i]->getLeft(), controls[i]->getTop(), controls[i]->getWidth(), controls[i]->getHeight()) )
		{
			OutputDebugStringW(L"RadioBox::mousePressed is inside\n");
			logicalPosition = i;
			RadioBox::selectOption();
		}
	}
}

void RadioBox::keyDown(WORD code, char charecter) {

	OutputDebugStringW(L"RadioBox::keyDown\n");

	switch (code) {
	case VK_UP:
		OutputDebugStringW(L"RadioBox::up\n");
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		else {
			logicalPosition = controls.size() - 1;
		}
		break;
	case VK_DOWN:
		OutputDebugStringW(L"RadioBox::down\n");
		if (logicalPosition < controls.size() - 1)
			logicalPosition++;
		else
			logicalPosition = 0;
		break;
	case VK_RETURN:
		RadioBox::selectOption();
		break;
	case VK_SPACE:
		RadioBox::selectOption();
		break;
	}
}

void RadioBox::SetList(vector<string> ListOfStrings, string Square_shape) {

	OutputDebugStringW(L"RadioBox::SetList\n");

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
		Add(tmp);
	}

	optionsSelected = vector<bool>(ListOfStrings.size());
	this->setHeight(controls.size());
	this->setWidth(maxsize + 1);

}
