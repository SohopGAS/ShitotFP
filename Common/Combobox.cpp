#include "Combobox.h"

// const
Combobox::Combobox()
{
	hasChosen = false;
}

// destrctor
Combobox::~Combobox()
{}


// implement mousePressed - check where pressed and update logicalPosition
void Combobox::mousePressed(int x, int y, bool isLeft) {
	Panel::mousePressed(x, y, isLeft);
	if (c.visable == true)
	{
		hasChosen == true;
		r.mousePressed(x, y, isLeft);
		string t = r.getChosen().substr(3, r.getChosen().length() - 2);
		l.setValue( t );
	}
}

// implemnt draw function 
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

// init the combobox 
void Combobox::init() {
	b.addListener(c);
	b.setValue(">");
	b.setTop(this->getTop());
	b.setLeft(this->getLeft());
	b.setWidth(2);
	b.setHeight(1);
	b.setColor(ColorType::Black, ColorType::Orange);
	b.setBorderType(this->getBorderType());

	l.setValue("Choose:   ");
	l.setTop(this->getTop());
	l.setLeft(this->getLeft() + 4);
	l.setWidth(l.getValue().size());
	l.setHeight(1);
	l.setColor(ColorType::Black, ColorType::Orange);
	l.setBorderType(this->getBorderType());

	r.setTop(this->getTop() + 2);
	r.setLeft(this->getLeft());
	r.setWidth(l.getValue().size());
	r.setHeight(10);
	r.setColor(ColorType::Black, ColorType::Orange);
	r.setBorderType(this->getBorderType());

	this->add(&r);
	this->add(&l);
	this->add(&b);
}

// setList function - input vector -list of string represnt label value , Square_shape add to the string 
void Combobox::setList(vector<string> ListOfStrings, string Square_shape) {
	r.setList(ListOfStrings, Square_shape);
}

// keyDown implement 
void Combobox::keyDown(WORD code, char charecter) {
	r.keyDown(code, charecter);
}

// focusOn - update the cursor position
void Combobox::focusOn() {
	if (c.visable == true) {
		this->setFocus(r);
		r.focusOn();
	}
	else {
		graphic.setCursorVisibility(false);
	}
};
