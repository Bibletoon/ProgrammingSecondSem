#include "RegularPolygon.h"

RegularPolygon::RegularPolygon(int pointsCount, Point* points) : Polygon(pointsCount, points)
{
	if (!_checkValid())
	{
		throw std::exception("Wrong data!");
	}
}

RegularPolygon::RegularPolygon(const RegularPolygon& regularPolygon) : Polygon(regularPolygon)
{
}

RegularPolygon::~RegularPolygon()
{
}

RegularPolygon& RegularPolygon::operator=(RegularPolygon const& regularPolygon)
{
	_pointsCount = regularPolygon._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = regularPolygon._points[i];
	}
	return *this;
}

bool RegularPolygon::_checkValid()
{
	float distance = _points[_pointsCount - 1].GetDistance(_points[0]);
	for (int i = 0; i < _pointsCount - 1; i++)
	{
		if (distance != _points[i].GetDistance(_points[i + 1])) return false;
	}
	return true;
}
