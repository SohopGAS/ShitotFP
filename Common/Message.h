#pragma once
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/Graphics.h"

#include "windows.h"



class OnPress : public MouseListener {
private:
	string title;
//	Message* msg;
public:


	void MousePressed(int x, int y, bool isLeft)
	{
		//OutputDebugStringW(L"MousePressed on OnPress\n");

		// i  1 = ok , 2 = cnacel
		int value_from_MB = MessageBoxA(nullptr, title.c_str(), "MessageBox", MB_OKCANCEL);
		if (value_from_MB == 1) {
			//msg->update(value_from_MB);
		}
		else {
		//	msg->update(value_from_MB);
		}
	}
	void setTitle(string s) { title = s; };
	string getTitle() { return title; };
	//void setMessage(Message* _msg) { msg = _msg; };

};



class Message : public Panel
{
private:
	OnPress onPress;
	Button press;

public:
	Message();
	~Message();
	void init();
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD code, char charecter);
	void setMassegeBoxText(string str) { onPress.setTitle(str); };
//	void update(int value_from_MB) {};
};
