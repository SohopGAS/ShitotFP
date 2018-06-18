#include "Control.h"

Control* Control::static_control = NULL;

Control::Control() {
  setLeft(0);
  setTop(0);
  setWidth(0);
  setHeight(0);
  setBackground(ColorType::White);
  setForeground(ColorType::Black);
};

Control::~Control() {

};

void Control::draw(Graphics& g, short x, short y, size_t z) {
	// TODO: add drow border
}
