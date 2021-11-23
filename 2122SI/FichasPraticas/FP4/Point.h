#pragma once
#include <math.h>
class Point {
private:
	int x, y;// coordenadas do ponto 
public:
	Point() {x = 0, y = 0;} // construtor por omissão 
	Point(int x0, int y0) { x = x0, y=y0; } //construtor para atribuição de novos valores
	void SetX(int new_x){x = new_x;} // nova coordenada X
	int GetX() { return x; } // devolve a coordenada X 
	void SetY(int new_y) { y = new_y; } // nova coordenada Y
	int GetY() { return y; } // devolve a coordenada Y
	float GetDistance(Point p2) { return sqrt(pow(x - p2.x, 2) + pow(y - p2.y, 2)); } // calcula a distancia a um ponto p2
};