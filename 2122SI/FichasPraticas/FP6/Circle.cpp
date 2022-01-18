#include "Circle.h"
#include "Window.h"
#include "Point.h"
#include <Windows.h>
#include "Line.h"
#include <stdio.h>
#include <stdlib.h>


Circle::Circle(){
	center = Point(0, 0);
	radius = 0;
	value = 0;
}
Circle::Circle(Point c, int r, int v){
	center = c;
	radius = r;
	value = v;
}
bool Circle::Contains(Point p){
	if (center.GetDistance(p) <= radius){
		return true;
	}
	else{
		return false;
	}
}

void Circle::Draw(HWND windowId, long cor)
{
	if (windowId != NULL)
	{
		HDC DrawHDC = GetDC(windowId);
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, cor);
		HPEN hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush;
		HBRUSH hNewBrush;
		hNewBrush = CreateSolidBrush(cor);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
		Ellipse(DrawHDC, center.GetX() - radius, center.GetY() + radius,center.GetX() + radius, center.GetY() - radius);
		char str[80];
		sprintf_s(str, "%d", value);
		SetBkMode(DrawHDC, TRANSPARENT);
		SetTextColor(DrawHDC, RGB(0, 0, 0));
		SetTextAlign(DrawHDC, TA_CENTER | TA_BOTTOM | TA_BASELINE);
		TextOut(DrawHDC, center.GetX(), center.GetY(), str, strlen(str));
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(windowId, DrawHDC);
	}
}