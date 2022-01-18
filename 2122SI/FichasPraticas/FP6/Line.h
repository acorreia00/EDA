#pragma once
#include <windows.h>

#include "Point.h"


class Line
{
private:
	Point pi, pf;
public:
	Line();
	Line(Point p1, Point p2);
	void Draw(HWND windowId, long cor);
	float GetLenght();
};