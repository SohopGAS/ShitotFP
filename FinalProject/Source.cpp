#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
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
		
			Add(&l);
		
			tb.setWidth(10);
			tb.setTop(1);
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
