#pragma once
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/Graphics.h"

#include "windows.h"



class OnPress : public MouseListener {
private:
	string title;
	int value_from_MB=0;
public:
	
	// set title 
	void setTitle(string s) { title = s; };
	
	// get title
	string getTitle() { return title; };
	int get_value_from_MB() { return value_from_MB; }

	// on mouse press listner update the value of value_from_MB
	// result:   1 = ok , 2 = cnacel
	void MousePressed(int x, int y, bool isLeft){ value_from_MB = MessageBoxA(nullptr, title.c_str(), "MessageBox", MB_OKCANCEL);} 
	

};



class Message : public Panel
{
private:
	OnPress onPress;
	Button press;

public:
	Message();
	~Message();
	
	// initialize MassageBox 
	void init();

	// change the value of button value and the massage box value
	void setMassegeBoxText(string button_value, string str) { onPress.setTitle(str); press.setValue(button_value); };

	// virtual function implement
	void keyDown(WORD code, char charecter) {};
	void draw(Graphics& g, short x, short y, size_t z);
	bool canGetFocus() { return false; };

};
