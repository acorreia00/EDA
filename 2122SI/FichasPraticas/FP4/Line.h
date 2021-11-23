#pragma once
#include <windows.h>
#include "Point.h"
class Line {
private:
	Point pi, pf; // pi - Initial point, pf - Final point
public:
	Line(); // Default constructor
	Line(Point p1, Point p2);
	void Draw(HWND wndId, long color); // Draw graphically a line between pi and pf
	double GetLength(); // Length of the line
};
