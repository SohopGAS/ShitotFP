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
	{
		hasChosen == true;
		r.mousePressed(x, y, isLeft);

		l.setValue( r.GetChosen() );
	}	
}
void Combobox::draw(Graphics& g, short x, short y, size_t z) {
	
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
	g.setCursorVisibility(false);


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
void Combobox::SetList(vector<string> ListOfStrings,string Square_shape) {

	r.SetList(ListOfStrings, Square_shape);

}


void Combobox::keyDown(WORD  code, char charecter) {
	r.keyDown(code, charecter);
}
