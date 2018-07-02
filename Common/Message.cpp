#include "Message.h"

Message::Message()
{
	setHeight(1);
	onPress.setTitle("pop up here : ");
}


Message::~Message()
{
}

void Message::draw(Graphics& g, short x, short y, size_t z) {
	Control::draw(g, this->getLeft(), this->getTop(), z);
	press.draw(g, x, y, z);
}

void Message::keyDown(WORD code, char charecter) {

}

void Message::init() {
	press.setValue("press here");
	press.setTop( getTop() );
	press.setLeft( getLeft() );
	press.setWidth( 10 );
	press.setColor(ColorType::Black, ColorType::Orange);
//	onPress.setMessage(this);
	press.AddListener(onPress);
	Add(&press);
	//this->setWidth(press.getWidth() );
	//this->setHeight(press.getHeight() );


}