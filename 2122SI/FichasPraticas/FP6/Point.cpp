#include "Point.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int x0, int y0)
{
	x = x0;
	y = y0;
}

void Point::SetXY(int novo_x, int novo_y)
{
	x = novo_x;
	y = novo_y;
}

float Point::GetDistance(Point p2)
{
	float xx, yy;
	xx = p2.x - x;
	yy = p2.y - y;

	return sqrt(pow(xx, 2) + pow(yy, 2));

}

int Point::GetX()
{
	return x;
}

int Point::GetY()
{
	return y;
}