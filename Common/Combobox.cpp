#include "Combobox.h"

Combobox::Combobox()
{
	hasChosen = false;
}

Combobox::~Combobox()
{
}
void Combobox::mousePressed(int x, int y, bool isLeft) {
	Panel::mousePressed(x, y, isLeft);
	if (c.visable == true)
		r.mousePressed(x, y, isLeft);

}
void Combobox::draw(Graphics& g, short x, short y, size_t z) {
	//Control::draw(g, x, y, z);

	if (c.visable == true) {
		l.draw(g, x, y, z);
		b.draw(g, x, y, z);
		r.draw(g, x, y, z);
		this->setWidth(b.getWidth() + r.getWidth());
		this->setHeight(b.getHeight() + r.getHeight());
	}
	else {
		l.draw(g, x, y, z);
		b.draw(g, x, y, z);
		this->setWidth(b.getWidth());
		this->setHeight(b.getHeight());
	}

};
void Combobox::func() {
	b.AddListener(c);
	b.setValue(">");
	b.setTop(this->getTop());
	b.setLeft(this->getLeft());
	b.setWidth(2);
	b.setHeight(1);
	b.setColor(ColorType::Black, ColorType::Orange);
	l.setBorderType(this->getBorderType());
	l.setValue("select option..");
	l.setTop(this->getTop());
	l.setLeft(this->getLeft() + 4);
	l.setWidth(l.getValue().size());
	l.setHeight(1);
	l.setColor(ColorType::Black, ColorType::Orange);
	b.setBorderType(this->getBorderType());

	r.setTop(this->getTop() + 2);
	r.setLeft(this->getLeft());
	r.setWidth(l.getValue().size());
	r.setHeight(10);
	r.setColor(ColorType::Black, ColorType::Orange);
	r.setBorderType(this->getBorderType());

	this->Add(&r);
	this->Add(&l);
	this->Add(&b);
}
void Combobox::SetList(vector<string> ListOfStrings) {

	r.SetList(ListOfStrings);

}
//#include "Combobox.h"
//
//Combobox::Combobox()
//{
//
//
//}
//
//Combobox::~Combobox()
//{
//}
//
//void Combobox::draw(Graphics& g, short x, short y, size_t z) {
//	Control::draw(g, x, y, z);
//	Panel::draw(g, x, y, z);
//}
//
//
//void Combobox::SetList(vector<string> ListOfStrings) {
//
//	// get size of list
//	int size = ListOfStrings.size();
//	int maxsize = 0;
//	int ezer = 0;
//	int heCalc = 1;
//	// itert throw the vector and find the longest string 
//	// inorder to keep in shape the entire list
//	for (int i = 0; i < size; i++) {
//		if (maxsize < ListOfStrings[i].size() - 1)
//			maxsize = ListOfStrings[i].size() - 1;
//	}
//	this->setWidth(maxsize + 1);
//	this->setHeight(ListOfStrings.size());
//	for (int i = 0; i < size; i++) {
//		ezer = maxsize - ListOfStrings[i].size() + 1;
//		if (ListOfStrings[i].size() - 1 < maxsize)
//			for (int j = 0; j < ezer; j++) {
//				ListOfStrings[i].insert(ListOfStrings[i].size(), " ");
//
//			}
//	}
//
//	// create label and puts in the list
//	for (int i = 0; i < size; i++) {
//		Control* tmp = (Control*)new Label(ListOfStrings[i]);
//		Add(tmp);
//	}
//
//
//	optionsSelected = vector<bool>(ListOfStrings.size());
//}
