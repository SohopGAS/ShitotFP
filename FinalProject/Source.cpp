#include "../Common/Graphics.h"
//#include "../Common/Label.h"
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
			l.setColor(Color::Blue, Color::Red);
			Add(&l);
		
			string ok("ok");
			b.setValue(ok);
			b.setLeft(10);
			b.setTop(10);
			b.setColor(Color::Orange, Color::Blue);
			b.setHeight(4);
			b.setWidth(10);
			
			Add(&b);
			
			

			
			tb.setWidth(50);
			tb.setTop(1);
			tb.setValue("hello world");
			tb.setLeft(1 + (short)value.size() + 1);
			Add(&tb);
		}

	};



int main(int argc, char** argv)
{
	std::ofstream myfile("Log.txt");
	myfile.open("Log.txt");
	


	
	//myfile.close();

	EventEngine e;
	Form f;
	e.run(f);
	
	
	
	
	

}
