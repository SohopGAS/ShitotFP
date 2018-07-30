#include "Message.h"

// constrctor
Message::Message()
{
	setHeight(1);
	onPress.setTitle("Generic Message pop up here:");
}

// destrctor
Message::~Message()
{}

// implement draw 
void Message::draw(Graphics& g, short x, short y, size_t z) {
	// draw border
	Control::draw(g, this->getLeft(), this->getTop(), z);
	press.draw(g, x, y, z);
}


// init function 
void Message::init() {
	press.setValue("Press Here");
	press.setTop(getTop());
	press.setLeft(getLeft());
	press.setWidth(10);
	press.setColor(ColorType::Black, ColorType::Orange);
	press.addListener(onPress);
	add(&press);
}

// set value show inside the massegebox
void Message::setMassegeBoxText(string button_value, string str) {
	onPress.setTitle(str);
	press.setValue(button_value);
}
