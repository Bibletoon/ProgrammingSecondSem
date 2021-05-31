#include "Trapezoid.h"

#include <iostream>

#include "Vector.h"

Trapezoid::Trapezoid(const Point& pointOne, const Point& pointTwo, const Point& pointThree, const Point& pointFour) :
	Polygon(4, new Point[4]{pointOne, pointTwo, pointThree, pointFour})
{
	if (!_checkValid())
	{
		throw std::exception("Wrong data!");
	}
}

Trapezoid::Trapezoid(Point* points) : Polygon(4, points)
{
	if (!_checkValid())
	{
		throw std::exception("Wrong data!");
	}
}

Trapezoid::Trapezoid(int pointsCount, Point* points) : Polygon(pointsCount, points)
{
	if (!_checkValid())
	{
		throw std::exception("Wrong data!");
	}
}

Trapezoid::~Trapezoid()
{
}

Trapezoid::Trapezoid(const Trapezoid& triangle) : Polygon(triangle)
{
}

Trapezoid& Trapezoid::operator=(Trapezoid const& trapezoid)
{
	_pointsCount = trapezoid._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = trapezoid._points[i];
	}
	return *this;
}

bool Trapezoid::_checkValid()
{
	Vector sideOne = Vector(_points[0], _points[1]);
	Vector sideTwo = Vector(_points[1], _points[2]);
	Vector sideThree = Vector(_points[2], _points[3]);
	Vector sideFour = Vector(_points[3], _points[0]);

	if (sideOne.GetCrossProduct(sideThree) == 0 && sideTwo.GetCrossProduct(sideFour) != 0) return true;
	if (sideOne.GetCrossProduct(sideThree) != 0 && sideTwo.GetCrossProduct(sideFour) == 0) return true;
	return false;
}
