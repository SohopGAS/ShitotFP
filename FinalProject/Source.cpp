#include <iostream>
#include <fstream>

#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/BorderType.h"
#include "../Common/DoubleLineBorder.h"
#include "../Common/SingleLineBorder.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include "../Common/Logger.h"
#include "../Common/RadioBox.h"
#include "../Common/NumericBox.h"
#include "../Common/Message.h"
using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
	CheckList ck;
	Button button;
	RadioBox rb;
	NumericBox nb;
	Message msg;

public:
		Control* _control;
		Form()
		{
			
			string value("Enter Name:");
			l.setValue(value);
			l.setTop(2);
			l.setLeft(5);
			l.setHeight(1);
			l.setWidth(12);
			l.setColor(ColorType::Black, ColorType::Orange);
			BorderType* b = SingleLineBorder::getinstance();
			l.setBorderType(b);

			Add(&l);

			button.setValue("button");
			button.setTop(2);
			button.setLeft(20);
			button.setWidth(button.getValue().size() + 2);
			button.setHeight(1);
			button.setColor(ColorType::Black, ColorType::Orange);
			button.setBorderType(b);
			
			Add(&button);

			tb.setWidth((short)value.size());
			tb.setTop(5);
			tb.setLeft(5);
			tb.setHeight(1);
			tb.setBorderType(b);
			tb.setColor(ColorType::Black, ColorType::Orange);
			
			Add(&tb);

			ck.SetList({ "ase","fre","asw","fds","vxv","fdfgggg" }, "[ ] ");
			ck.setTop(8);
			ck.setLeft(5);
			ck.setBorderType(b);
			ck.setColor(ColorType::Black, ColorType::Orange);
			_control = &tb;
			Add(&ck);
			

			rb.setTop(8);
			rb.setLeft(20);
			rb.setBorderType(b);
			rb.setColor(ColorType::Black, ColorType::Orange);
			rb.init();

			Add(&rb);

			nb.setTop(15);
			nb.setLeft(23);
			nb.setBorderType(b);
			nb.SetMaxValue(10);
			nb.SetMinValue(2);
			nb.setColor(ColorType::Black, ColorType::Orange);
			nb.init();
			Add(&nb);

			msg.setTop(18);
			msg.setLeft(8);
			msg.setBorderType(b);
			msg.setWidth(10);
			msg.setHeight(1);
			msg.setColor(ColorType::Black, ColorType::Orange);
			msg.init();
			Add(&msg);
				
		}

};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	f.setWidth(40);
	f.setHeight(20);
	f.setTop(0);
	f.setLeft(0);
	BorderType* bo = DoubleLineBorder::getinstance();
	f.setBorderType(bo);
	f.setFocus(*f._control);
	e.run(f);
}