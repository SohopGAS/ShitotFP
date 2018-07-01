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
<<<<<<< HEAD
//#include "../Common/Logger.h"

=======
#include "../Common/Logger.h"
#include "../Common/RadioBox.h"
#include "../Common/NumericBox.h"
#include "../Common/Message.h"
>>>>>>> e4194c59f25c5d0d7c4b091f1538e719195407b4
using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l;
<<<<<<< HEAD
	// Button b;
=======
	CheckList ck;
<<<<<<< HEAD
	Button b;
>>>>>>> master


public:
=======
	Button button;
	RadioBox rb;
	NumericBox nb;
	Message msg;

public:
		Control* _control;
>>>>>>> e4194c59f25c5d0d7c4b091f1538e719195407b4
		Form()
		{

			string value("Enter Name:");
<<<<<<< HEAD
			// l.setValue(value);
			// l.setTop(1);
			// l.setLeft(5);
			// l.setHeight(1);
			// l.setWidth(12);
			// l.setColor(ColorType::Black, ColorType::Orange);
			//BorderType* bd = SingleLineBorder::getinstance();
			// l.setBorderType(bd);
			//
			// Add(&l);

			tb.setWidth((short)value.size());
			tb.setTop(3);
			tb.setHeight(1);
			//tb.setBorderType(bd);
			tb.setColor(ColorType::Black, ColorType::Orange);
			tb.setLeft(5);

			Add(&tb);

<<<<<<< HEAD
			// ck.SetList({ "ase","fre","asw","fds","vxv","fdfgggg" }, "[ ] ");
			// ck.setTop(5);
			// ck.setLeft(5);
			// ck.setBorderType(bd);
			// ck.setColor(ColorType::Black, ColorType::Orange);
			// _control = &tb;
			// Add(&ck);

=======
			l.setValue(value);
			l.setTop(1);
			l.setLeft(1);
			l.setColor(ColorType::Blue, ColorType::Red);
<<<<<<< HEAD

			Add(&l);

			// string buttonOf("BUTTON");
			// b.setValue(buttonOf);
			// b.setTop(5);
			// b.setLeft(10);
			// b.setColor(ColorType::Red, ColorType::Green);
			// string buttonChange("button1");
			// b.setValue(buttonChange);
			//
			// Add(&b);
=======

			Add(&l);
>>>>>>> master

			tb.setValue("My TextBox Example");
			tb.setTop(50);
			tb.setLeft(1 + (short)value.size() + 1);
			tb.setHeight(50);
			tb.setWidth(50);
<<<<<<< HEAD

			Add(&tb);

=======

			Add(&tb);
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
=======
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
				
>>>>>>> e4194c59f25c5d0d7c4b091f1538e719195407b4
>>>>>>> master
		}

};



int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
<<<<<<< HEAD
	f.setWidth(30);
	f.setHeight(15);
	f.setTop(0);
	f.setLeft(0);
	BorderType* bo = SingleLineBorder::getinstance();
	f.setBorderType(bo);
	Control::setFocus(f);
//	f.setFocus(*f._control);
=======
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
	e.run(f);
}
