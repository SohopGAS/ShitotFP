#include "Label.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {};

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    g.moveTo(10, 10);
    if (!z)
        g.write(value);

}
