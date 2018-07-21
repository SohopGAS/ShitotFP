#include "Message.h"

Message::Message()
{
	setHeight(1);
	onPress.setTitle("Generic Message pop up here:");
}


Message::~Message()
{
}

void Message::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, this->getLeft(), this->getTop(), z);
	press.draw(g, x, y, z);
}

void Message::init() {
	press.setValue("Press Here");
	press.setTop(getTop());
	press.setLeft(getLeft());
	press.setWidth(10);
	press.setColor(ColorType::Black, ColorType::Orange);
	press.AddListener(onPress);
	add(&press);
}


void Message::setMassegeBoxText(string button_value, string str) {
	onPress.setTitle(str);
	press.setValue(button_value);
};
