#define _CRT_SECURE_NO_WARNINGS
#include"Circle.h"

void Circle::Draw(HWND wndId, long color){
	if(wndId != NULL){
		HDC DrawHDC = GetDC(wndId); // penstyle, width, color
		HPEN   hNPen = CreatePen(PS_SOLID, 2, color);
		HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush;
		HBRUSH hNewBrush;
		hNewBrush = CreateSolidBrush(color);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
		Ellipse(DrawHDC, center.GetX()-radius, center.GetY()+radius,center.GetX()+radius, center.GetY()-radius);
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(wndId, DrawHDC);
	}
}

void Circle::Draw(HWND wndId, long color, const char* text, long text_color)
{
	if (wndId != NULL)
	{
		HDC DrawHDC = GetDC(wndId);
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, color);
		HPEN hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush;
		HBRUSH hNewBrush;
		hNewBrush = CreateSolidBrush(color);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
		Ellipse(DrawHDC, center.GetX() - radius, center.GetY() + radius,
			center.GetX() + radius, center.GetY() - radius);
		SetBkMode(DrawHDC, TRANSPARENT);
		SetTextColor(DrawHDC, text_color);
		SetTextAlign(DrawHDC, TA_CENTER | TA_BASELINE);
		TextOut(DrawHDC, center.GetX(), center.GetY() + 3, text, strlen(text));
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(wndId, DrawHDC);
	}
}

bool Circle::Contains(Point p) {
	if (pow(p.GetX() - center.GetX(), 2) + pow(p.GetY() - center.GetY(), 2) < pow(radius, 2)) return true;
	else return false;
}