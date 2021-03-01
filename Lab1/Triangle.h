#pragma once
#include "Polygon.h"
class Triangle : public Polygon
{
public:
	Triangle(const Point& pointOne, const Point& pointTwo, const Point& pointThree);
	Triangle(Point* points);
	Triangle(int pointsCount, Point* points);
	~Triangle();
	Triangle(const Triangle& triangle);
	Triangle& operator = (Triangle const& triangle);
	bool IsRight() const;
};
