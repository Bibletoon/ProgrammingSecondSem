#pragma once
#include "Polygon.h"

class Trapezoid : public Polygon
{
public:
	Trapezoid(const Point& pointOne, const Point& pointTwo, const Point& pointThree, const Point& pointFour);
	Trapezoid(Point* points);
	Trapezoid(int pointsCount, Point* points);
	~Trapezoid();
	Trapezoid(const Trapezoid& triangle);
	Trapezoid& operator =(Trapezoid const& triangle);
protected:
	bool _checkValid() override;
};
