#include "../Common/CheckList.h"
#include "../Common/Label.h"

void CheckList::keyDown(WORD code, char chr) {

	switch (code) {
	case VK_UP:
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		else {
			logicalPosition = controls.size() - 1;
		}
		//Checklist::Update();
		break;
	case VK_DOWN:
		if (logicalPosition < controls.size() - 1) {
			logicalPosition++;
		}
		else {
			logicalPosition = 0;
		}
		//Checklist::Update();
		break;

	case VK_RETURN:
	case VK_SPACE:
		CheckList::selectOption();
		break;

	}
}




void CheckList::SetList(vector<string> ListOfStrings) {
	string Square_shape = "[ ]";

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

	// create label and puts in the list
	for (int i = 0; i < size; i++) {
		Control* tmp = (Control*)new Label(ListOfStrings[i]);
		tmp->setTop(this->getTop() + i);
		tmp->setLeft(this->getLeft());
		tmp->setWidth(maxsize);
		tmp->setHeight(1);
		Add(tmp);
	}

	optionsSelected = vector<bool>(ListOfStrings.size());
	this->setHeight(controls.size());
	this->setWidth(maxsize + 1);

}


void CheckList::SelectIndex(size_t index) {
	logicalPosition = index;
	selectOption();
}
void CheckList::DeselectIndex(size_t index) {
	logicalPosition = index;
	selectOption();
}

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


vector<size_t> CheckList::GetSelectedIndexs() {
	vector<size_t> result;
	for (int i = 0; i < optionsSelected.size(); i++) {
		if (optionsSelected[i] == true) {
			result.push_back(i);
		}
	}
	return result;
}


void CheckList::draw(Graphics &g, short left, short top, size_t layer)
{
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

bool CheckList::indexInVector() {
	return optionsSelected[logicalPosition];
}

void CheckList::focusOn() {
	graphic.moveTo(left + 1, top + logicalPosition);
};


CheckList::CheckList()
{

}

CheckList::~CheckList()
{
}