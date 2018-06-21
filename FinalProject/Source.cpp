#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/SingleLineBorder.h"
#include "../Common/Button.h"
#include <iostream>
#include <fstream>
#include "../Common/CheckList.h"
#include "../Common/Logger.h"
using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
	CheckList ck;
	Button b;


public:
	Control* _control;
		Form()
		{

			string value("Enter Name:");
			l.setValue(value);
			l.setTop(1);
			l.setLeft(5);
			l.setHeight(1);
			l.setWidth(12);
			l.setColor(ColorType::Black, ColorType::Orange);
			BorderType* bd = SingleLineBorder::getinstance();
			l.setBorderType(bd);

			Add(&l);

			tb.setWidth((short)value.size());
			tb.setTop(3);
			tb.setHeight(1);
			tb.setBorderType(b);
			tb.setValue("hello world");
			tb.setColor(ColorType::Black, ColorType::Orange);
			tb.setLeft(5);

			Add(&tb);

			ck.SetList({ "ase","fre","asw","fds","vxv","fdfgggg" }, "[ ] ");
			ck.setTop(5);
			ck.setLeft(5);
			ck.setBorderType(b);
			ck.setColor(ColorType::Black, ColorType::Orange);
			_control = &tb;
			Add(&ck);

		}

};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	f.setWidth(30);
	f.setHeight(15);
	f.setTop(0);
	f.setLeft(0);
	BorderType* bo = SingleLineBorder::getinstance();
	f.setBorderType(bo);
	f.setFocus(*f._control);
	e.run(f);
}
