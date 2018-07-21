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
#include "../Common/Combobox.h"

using namespace std;

class Form : public Panel
{
	TextBox tb;
	Label l, l2, l3, l4, l5;
	CheckList ck;
	Button button;
	RadioBox rb;
	NumericBox nb;
	Message msg;
	Combobox cb;
	BorderType* b = SingleLineBorder::getinstance();

public:
		Form()
		{

			string value("Enter Name:");
			l.setValue(value);
			l.setTop(2);
			l.setLeft(2);
			l.setHeight(1);
			l.setWidth(12);
			l.setColor(ColorType::Black, ColorType::Orange);
			b = SingleLineBorder::getinstance();
			l.setBorderType(b);
			add(&l);

			tb.setWidth((short)value.size());
			tb.setTop(2);
			tb.setLeft(20);
			tb.setHeight(1);
			tb.setWidth(17);
			tb.setBorderType(b);
			tb.setColor(ColorType::Black, ColorType::Orange);
			add(&tb);

			string value2("Department:");
			l2.setValue(value2);
			l2.setTop(5);
			l2.setLeft(2);
			l2.setHeight(1);
			l2.setWidth(12);
			l2.setColor(ColorType::Black, ColorType::Orange);
			b = SingleLineBorder::getinstance();
			l2.setBorderType(b);
			add(&l2);

			rb.setTop(5);
			rb.setLeft(20);
			rb.setBorderType(b);
			rb.setColor(ColorType::Black, ColorType::Orange);
			rb.setList({ "Art","Design","Engineering"},"( )" );
			add(&rb);

			string value3("Addicted to:");
			l3.setValue(value3);
			l3.setTop(10);
			l3.setLeft(2);
			l3.setHeight(1);
			l3.setWidth(12);
			l3.setColor(ColorType::Black, ColorType::Orange);
			b = SingleLineBorder::getinstance();
			l3.setBorderType(b);
			add(&l3);

			cb.setTop(10);
			cb.setLeft(20);
			cb.setBorderType(b);
			cb.setWidth(10);
			cb.setHeight(1);
			cb.init();
			cb.setList({"Bamba","Grass","Caffeine","Other"}, "   ");
			cb.setColor(ColorType::Black, ColorType::Orange);
			add(&cb);

			string value4("Year study:");
			l4.setValue(value4);
			l4.setTop(2);
			l4.setLeft(40);
			l4.setHeight(1);
			l4.setWidth(12);
			l4.setColor(ColorType::Black, ColorType::Orange);
			b = SingleLineBorder::getinstance();
			l4.setBorderType(b);
			add(&l4);

			nb.setTop(2);
			nb.setLeft(56);
			nb.setBorderType(b);
			nb.SetMaxValue(4);
			nb.SetMinValue(1);
			nb.setColor(ColorType::Black, ColorType::Orange);
			nb.init();
			add(&nb);

			string value5("Internship courses:");
			l5.setValue(value5);
			l5.setTop(7);
			l5.setLeft(40);
			l5.setHeight(1);
			l5.setWidth(18);
			l5.setColor(ColorType::Black, ColorType::Orange);
			b = SingleLineBorder::getinstance();
			l5.setBorderType(b);
			add(&l5);

			ck.setTop(10);
			ck.setLeft(40);
			ck.setBorderType(b);
			ck.setColor(ColorType::Black, ColorType::Orange);
			ck.setList({"Machine Learning","Artificial Intelligence","Internet Of Things","WEB and Cloud","Design & Develop Algorithms","Hardware Security"});
			add(&ck);

			button.setValue("Cancel");
			button.setTop(18);
			button.setLeft(50);
			button.setWidth(button.getValue().size() + 2);
			button.setHeight(1);
			button.setColor(ColorType::Black, ColorType::Orange);
			button.setBorderType(b);
			add(&button);

			msg.setTop(18);
			msg.setLeft(8);
			msg.setBorderType(b);
			msg.setWidth(10);
			msg.setHeight(1);
			msg.setColor(ColorType::Black, ColorType::Orange);
			msg.init();
			add(&msg);

			Control::setFocus(tb);
		}

};

int main(int argc, char** argv)
{
	EventEngine e;
	Form f;
	f.setWidth(74);
	f.setHeight(22);
	f.setTop(0);
	f.setLeft(0);
	BorderType* bo = DoubleLineBorder::getinstance();
	f.setBorderType(bo);
	e.run(f);
}
