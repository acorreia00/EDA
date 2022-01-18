#include "Line.h"
#include "Point.h"
#include <math.h>

Line::Line() {
	pi = Point(0, 0);
	pf = Point(0, 0);
}
Line::Line(Point p1, Point p2) {
	pi = p1;
	pf = p2;
}
void Line::Draw(HWND windowId, long cor)
{
	if (windowId != NULL)
	{
		HPEN hOPen;
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, cor);
		HDC DrawHDC = GetDC(windowId);
		hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		// starting point of line
		MoveToEx(DrawHDC, pi.GetX(), pi.GetY(), NULL);
		// ending point of line
		LineTo(DrawHDC, pf.GetX(), pf.GetY());
		DeleteObject(SelectObject(DrawHDC, hOPen));
		ReleaseDC(windowId, DrawHDC);
	}
}
float Line::GetLenght() {
	float xx, yy;
	xx = pf.GetX() - pi.GetX();
	yy = pf.GetY() - pi.GetY();

	return sqrt(pow(xx, 2) + pow(yy, 2));
}