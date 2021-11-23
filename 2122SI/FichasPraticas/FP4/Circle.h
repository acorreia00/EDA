#pragma once
#include<windows.h>
#include"Point.h"
class Circle{
private:
	Point center; // coordenadas do centro
	int radius; // raio do círculo
public:
	Circle() {radius = 0; } // construtor por omissão
	Circle(Point c, int r) { center=c, radius=r; }
	void Draw(HWND wndId, long color);// Desenha graficamente o circulo
	bool Contains(Point p); // verifica se o ponto está dentro do circulo
};
