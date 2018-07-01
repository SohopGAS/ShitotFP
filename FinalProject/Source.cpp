#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/SingleLineBorder.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include "../Common/RadioBox.h"
#include "../Common/NumericBox.h"
#include "../Common/Message.h"
//#include "../Common/Logger.h"

#include <iostream>
#include <fstream>

using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
	CheckList cl;
	Button b1,  b2;
	RadioBox rb;
	NumericBox nb;
	Message msg;

public:
		Control* _control;
		Form()
		{
			tb.setWidth((short)value.size());
			tb.setTop(3);
			tb.setHeight(1);
			//tb.setBorderType(bd);
			tb.setColor(ColorType::Black, ColorType::Orange);
			tb.setLeft(5);
			Add(&tb);
			// _control.add(&tb);

			l.setValue(value);
			l.setTop(1);
			l.setLeft(1);
			l.setColor(ColorType::Blue, ColorType::Red);
			Add(&l);

			tb.setValue("My TextBox Example");
			tb.setTop(50);
			tb.setLeft(1 + (short)value.size() + 1);
			tb.setHeight(50);
			tb.setWidth(50);
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
	f.setWidth(30);
	f.setHeight(15);
	f.setTop(0);
	f.setLeft(0);
	BorderType* bo = SingleLineBorder::getinstance();
	f.setBorderType(bo);
	Control::setFocus(f);
//	f.setFocus(*f._control);
	e.run(f);
}
