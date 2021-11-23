#include"Line.h"
Line::Line()
{
	pi.SetX(0);
	pi.SetY(0);
	pf.SetX(0);
	pf.SetY(0);
}
Line::Line(Point p1, Point p2)
{
	pi = p1;
	pf = p2;
}
void Line::Draw(HWND wndId, long color)
{
	if (wndId != NULL)
	{
		if (wndId != NULL)
		{
			HPEN hOPen;
			// penstyle, width, color
			HPEN hNPen = CreatePen(PS_SOLID, 2, color);
			HDC DrawHDC = GetDC(wndId);
			hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
			// starting point of line
			MoveToEx(DrawHDC, pi.GetX(), pi.GetY(), NULL);
			// ending point of line
			LineTo(DrawHDC, pf.GetX(), pf.GetY());
			DeleteObject(SelectObject(DrawHDC, hOPen));
			ReleaseDC(wndId, DrawHDC);
		}
	}
}
double Line::GetLength() 
{
	return sqrt(pow(pf.GetX() - pi.GetX(), 2) + pow(pf.GetY() - pi.GetY(), 2));
}
