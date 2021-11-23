#pragma once
#include<windows.h>
#include"Point.h"
class Circle{
private:
	Point center; // coordenadas do centro
	int radius; // raio do c�rculo
public:
	Circle() {radius = 0; } // construtor por omiss�o
	Circle(Point c, int r) { center=c, radius=r; }
	void Draw(HWND wndId, long color);// Desenha graficamente o circulo
	bool Contains(Point p); // verifica se o ponto est� dentro do circulo
};
