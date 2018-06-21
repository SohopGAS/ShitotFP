#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/SingleLineBorder.h"
#include "../Common/Button.h"
#include <iostream>
#include <fstream>
#include "../Common/Logger.h"
using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
	// Button b;

public:
		Form()
		{

			string value("Enter Name:");
			l.setValue(value);
			l.setTop(3);
			l.setLeft(10);
			l.setHeight(1);
			l.setWidth(12);
			l.setColor(ColorType::Blue, ColorType::Red);
			BorderType* b;
			// BorderType* b = SingleLineBorder::getinstance();
			l.setBorderType(b);

			Add(&l);

			tb.setWidth((short)value.size());
			tb.setTop(8);
			tb.setHeight(1);
			tb.setBorderType(b);

			tb.setValue("hello world");
			tb.setColor(ColorType::Green, ColorType::Orange);
			tb.setLeft(1 + (short)value.size() + 1);

			Add(&tb);


		}

};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	f.setWidth(30);
	f.setHeight(15);
	BorderType* bo;
	// BorderType* bo = SingleLineBorder::getinstance();
	f.setBorderType(bo);
	e.run(f);
}
