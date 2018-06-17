#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
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
			l.setTop(1);
			l.setLeft(1);
			l.setColor(Color::Blue, Color::Red);

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
	BorderType* b = new SingleLineBorder->getinstance();
	f.setBorderType(b);
	e.run(f);
}
