#pragma once

class MouseListener
{
public:
	virtual void MousePressed(int x, int y, bool isLeft) = 0;
};
