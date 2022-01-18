#pragma once
#include <windows.h>
#include "Point.h"

class Circle{
private:
	Point center; // coordenadas centro
	int radius; // raio circulo
	int value; // numero dentro do circulo
public:
	Circle(); // construtor defeito
	Circle(Point c, int r, int v);
	void Draw(HWND windowId, long cor); // Desenha o circulo
	bool Contains(Point p); // verifica se o ponto esta dentro do circulo
};
