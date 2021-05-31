#include "Vector.h"

Vector::Vector(const Point& pointOne, const Point& pointTwo)
{
	_x = pointTwo.GetX() - pointOne.GetX();
	_y = pointTwo.GetY() - pointOne.GetY();
}

float Vector::GetX() const
{
	return _x;
}

float Vector::GetY() const
{
	return _y;
}

float Vector::GetCrossProduct(const Vector& vector) const
{
	return _x * vector._y - _y * vector._x;
}

float Vector::GetScalarProduct(const Vector& vector) const
{
	return _x * vector._x + _y * vector._y;
}
