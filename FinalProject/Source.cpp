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
	Button button;

public:
		Form()
		{

			BorderType* b = SingleLineBorder::getinstance();

			string value("label");
			l.setValue(value);
			l.setTop(3);
			l.setLeft(5);
			l.setHeight(1);
			l.setWidth( value.size() ) ;
			l.setBorderType(b);
			l.setColor(ColorType::Blue, ColorType::Red);

			Add(&l);

			tb.setValue("text box");
			tb.setWidth( tb.getValue().size() );
			tb.setLeft(1 + (short)value.size() + 1);
			tb.setTop(8);
			tb.setHeight(1);
			tb.setBorderType(b);
			tb.setColor(ColorType::Green, ColorType::Orange);
			
			Add(&tb);

			button.setValue("button");
			button.setBorderType(b);
			button.setTop(12);
			button.setHeight(1);
			button.setWidth(button.getValue().size() );
			button.setLeft(2);
			button.setColor(ColorType::Purple,ColorType::Orange);
			Add(&button);

		}

};



int main(int argc, char** argv)
{
	

	EventEngine e;
	Form f;
	f.setWidth(70);
	f.setHeight(25);
	BorderType* bo = SingleLineBorder::getinstance();
	f.setBorderType(bo);
	e.run(f);
}
