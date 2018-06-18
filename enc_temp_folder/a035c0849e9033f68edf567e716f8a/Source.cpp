#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/SingleLineBorder.h"
#include <iostream>

using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;

public:

		Form()
		{
			
			string value("Enter Name:");
			l.setValue(value);
			l.setTop(2);
			l.setLeft(2);
			l.setHeight(4);
			l.setWidth(4);
			l.setColor(Color::Blue, Color::Red);
			BorderType* b = SingleLineBorder::getinstance();
			l.setBorderType(b);

			Add(&l);
		
			tb.setWidth(50);
			tb.setTop(1);
			tb.setValue("hello world");
			tb.setLeft(1 + (short)value.size() + 1);
			Add(&tb);
		}

	};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	
	e.run(f);
}
