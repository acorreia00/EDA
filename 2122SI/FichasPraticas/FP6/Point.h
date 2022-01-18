#pragma once

class Point{

private:
	int x, y;
public:
	Point();
	Point(int x0, int y0);

	void SetXY(int novo_x, int novo_y);
	float GetDistance(Point p2);

	int GetX();
	int GetY();
};
