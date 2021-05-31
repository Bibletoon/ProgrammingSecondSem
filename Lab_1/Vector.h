#pragma once
#include "Point.h"

class Vector
{
public:
	Vector(const Point& pointOne, const Point& pointTwo);
	float GetCrossProduct(const Vector& vector) const;
	float GetScalarProduct(const Vector& vector) const;
	float GetX() const;
	float GetY() const;
private:
	float _x, _y;
};
