#include "Point.h"

#include <cmath>
Point::Point(float x, float y)
{
	_x = x;
	_y = y;
}

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::~Point()
{
}

Point::Point(const Point& point)
	: _x(point._x), _y(point._y)
{
}

Point& Point::operator =(const Point& point)
{
	_x = point._x;
	_y = point._y;
	return *this;
}

float Point::GetX() const
{
	return _x;
}

float Point::GetY() const
{
	return _y;
}

std::tuple<int, int> Point::GetCoordinates() const
{
	return std::make_tuple(_x, _y);
}

void Point::SetX(float x)
{
	_x = x;
}

void Point::SetY(float y)
{
	_y = y;
}

void Point::SetCoordinates(float x, float y)
{
	_x = x;
	_y = y;
}

float Point::GetDistance(const Point& point) const
{
	return std::sqrt((point._x - _x) * (point._x - _x) + (point._y - _y) * (point._y - _y));
}