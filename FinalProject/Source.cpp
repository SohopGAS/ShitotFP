#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include <iostream>
#include <fstream>
#include "../Common/Logger.h"
using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
	Button b;

public:
		Form()
		{

			string value("Enter Name:");
			l.setValue(value);
			l.setTop(1);
			l.setLeft(1);
			l.setColor(ColorType::Blue, ColorType::Red);
			
			Add(&l);
			
			string buttonOf("BUTTON");
			b.setValue(buttonOf);
			b.setTop(5);
			b.setLeft(10);
			b.setColor(ColorType::Red, ColorType::Green);
			string buttonChange("button1");
			b.setValue(buttonChange);

			Add(&b);

			tb.setValue("My TextBox Example");
			tb.setTop(50);
			tb.setLeft(1 + (short)value.size() + 1);
			tb.setHeight(50);
			tb.setWidth(50);
<<<<<<< HEAD

			Add(&tb);
=======
			
			Add(&tb);
			
>>>>>>> origin/master
		}
	};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	e.run(f);
}
