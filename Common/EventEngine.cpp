#include "EventEngine.h"
#include "Logger.h"
#include <vector>
#include <algorithm>
using namespace std;

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	CLogger::GetLogger()->Log("event engine runinng");
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);

			/* chenge z < 5 to z < 1 to fix bug  
			for (size_t z = 0; z < 1; ++z)
			{
				c.draw(_graphics, 0, 0, z);
			}	*/

			for (size_t z = 0; z < 5; ++z)
			{
				c.draw(_graphics, 0, 0, z);
			}	
			redraw = false;
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			CLogger::GetLogger()->Log("key event");
			auto f = Control::getFocus();
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
					moveFocus(c, f);
				else
					f->keyDown(code, chr);
				redraw = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			CLogger::GetLogger()->Log("MouseEvent");
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				CLogger::GetLogger()->Log("Mouse option left or right");
				c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());
	Control::setFocus(**it);
}