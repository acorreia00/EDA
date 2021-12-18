#pragma once
#include<windows.h>
#include"Point.h"

class Circle{
private:
	Point center; // coordenadas centro
	int radius; // raio circulo
public:
	Circle() {radius = 0; } // construtor por omissão
	Circle(Point c, int r) { center=c, radius=r; }
	void Draw(HWND wndId, long color); // Desenhar circulo
	void Draw(HWND wndId, long color, const char* text, long text_color);
	bool Contains(Point p); //ponto dentro do circulo? s/n
};
