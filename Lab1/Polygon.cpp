#include "Polygon.h"

#include <iostream>

#include "Vector.h"

Polygon::Polygon(int pointsCount, Point* points) : ClosedPolygonalChain(pointsCount, points)
{
	if (!_checkValid())
	{
		throw std::exception("Wrong data!");
	}
}

Polygon::Polygon(const Polygon& polygon) : ClosedPolygonalChain(polygon)
{
}

Polygon::~Polygon()
{
}

Polygon& Polygon::operator=(Polygon const& polygon)
{
	_pointsCount = polygon._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = polygon._points[i];
	}
	return *this;
}

float Polygon::GetArea() const
{
	float area = 0;
	for (int i = 0; i < _pointsCount - 1; i++)
	{
		area += _points[i].GetX() * _points[i + 1].GetY();
	}
	area += _points[_pointsCount - 1].GetX() * _points[0].GetY();
	for (int i = 0; i < _pointsCount - 1; i++)
	{
		area -= _points[i + 1].GetX() * _points[i].GetY();
	}
	area -= _points[0].GetX() * _points[_pointsCount - 1].GetY();
	area /= 2;
	area = std::abs(area);
	return area;
}

bool Polygon::_checkValid()
{
	bool wasZero = false;
	if (_pointsCount < 3) return false;
	float product = Vector(_points[0], _points[1]).GetCrossProduct(Vector(_points[1], _points[2]));
	bool sign = product > 0;
	wasZero = sign == 0;
	for (int i = 1; i < _pointsCount - 2; i++)
	{
		product = Vector(_points[i], _points[i + 1]).GetCrossProduct(Vector(_points[i + 1], _points[i + 2]));
		if (sign != (product > 0) || (wasZero && product == 0)) return false;
		wasZero = sign == 0;
	}
	product = Vector(_points[_pointsCount - 2], _points[_pointsCount - 1]).GetCrossProduct(Vector(_points[_pointsCount - 1], _points[0]));
	if (sign != (product > 0) || (wasZero && product == 0)) return false;
	wasZero = sign == 0;
	product = Vector(_points[_pointsCount - 1], _points[0]).GetCrossProduct(Vector(_points[0], _points[1]));
	if (sign != (product > 0) || (wasZero && product == 0)) return false;
	return true;
}