#include "CheckList.h"


void CheckList::draw(Graphics &g, short left, short top, size_t layer)
{
	Control::draw(g, this->getLeft(), this->getTop() , layer);
	
	int vector_size = _options.size();
	g.moveTo(this->getLeft() , this->getTop() );

	for (int i = 0; i < vector_size; i++) {
		g.setBackground(this->bg);
		g.setForeground(this->fg);
		if (i == logicalPosition) {
			if (Control::getFocus() == this) {
				g.setBackground(ColorType::Red);
			}
			g.write(_options[i]);
			g.moveTo(this->getLeft() , this->getTop()  + i + 1);

		}
		else {
			g.setBackground(this->bg);
			g.setForeground(this->fg);
			g.write(_options[i]);
			g.moveTo(this->getLeft() , this->getTop() + i + 1);
		}

	}
	
	//g.setBackground(this->bg);

}

//void CheckList::Update() {
//	Control::graphics.clearScreen();
//	this->draw(Control::graphics, panelLeft, panelTop, 1);
//	Control::graphics.moveTo(panelLeft + 2, panelTop + logicalPosition + 1);
//}

void CheckList::keyDown(WORD code, char chr) {
	OutputDebugStringW(L"CheckList:: keyDown\n");

	switch (code) {
	case VK_UP:
		if (logicalPosition >= 1) {
			logicalPosition--;
		}
		else {
			logicalPosition = _options.size() - 1;
		}
		//Checklist::Update();
		break;
	case VK_DOWN:
		if (logicalPosition < _options.size() - 1) {
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
		//Checklist::Update();
		break;

	}
}

//void CheckList::mousePressed(int x, int y, bool isLeft) {
//	if (isInside(x, y, this->getLeft(), this->getTop(), this->getWidth(), this->getHeight()))
//	{
//		//dos
//	}
//	
//}

void CheckList::SetList(vector<string> ListOfStrings, string Square_shape = "( ) ") {
	_options = ListOfStrings;
	int size = ListOfStrings.size();
	int maxsize = 0;
	int ezer = 0;
	int heCalc = 1;
	for (int i = 0; i < size; i++) {
		
		_options[i].insert(0, Square_shape);
		if (maxsize < _options[i].size() - 1)
			maxsize = _options[i].size() - 1;
	}
	this->setWidth(maxsize + 1);
	this->setHeight(_options.size());
	for (int i = 0; i < size; i++) {
		ezer = maxsize - _options[i].size() +1;
		if (_options[i].size() -1 < maxsize)
			for (int j = 0; j < ezer; j++) {
				_options[i].insert(_options[i].size(), " ");
				
			}
		
	}
	
	optionsSelected = vector<bool>(ListOfStrings.size());
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

	if (!ifFirstButton || !isInside(x, y, this->getLeft() , this->getTop(), this->getWidth(),this->getHeight()) ) {
		//||x != this->getLeft() + 2
		return;
	}
	
		Control::setFocus(*this);
		int pressed = y - this->getTop() - 1;
		if (pressed >= _options.size()) {
			return;
		}
		logicalPosition = pressed;
		selectOption();
	
}

void  CheckList::selectOption() {
	if (optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = false;
		//g.moveTo(this->getLeft() + 2, this->getTop() + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, " ");
	}
	else {
		//g.moveTo(this->getLeft() + 2,this->getTop() + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, "X");
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

bool CheckList::indexInVector() {
	return optionsSelected[logicalPosition];
}


CheckList::CheckList()
{

}

CheckList::~CheckList()
{
}