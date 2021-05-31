#include "PolygonalChain.h"

#include <iostream>
#include <stdexcept>

//TODO: Make Point* const
PolygonalChain::PolygonalChain(int pointsCount, Point* points)
{
	_pointsCount = pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < pointsCount; i++)
	{
		_points[i] = points[i];
	}
}

PolygonalChain::~PolygonalChain()
{
	delete[] _points;
}

PolygonalChain::PolygonalChain(const PolygonalChain& polygonalChain)
	: _pointsCount(polygonalChain._pointsCount)
{
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = polygonalChain._points[i];
	}
}

PolygonalChain& PolygonalChain::operator=(PolygonalChain const& polygonalChain)
{
	_pointsCount = polygonalChain._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = polygonalChain._points[i];
	}
	return *this;
}

Point PolygonalChain::GetPoint(int index) const
{
	if (index < 0 || index >= _pointsCount) throw std::out_of_range("Wrong index was given.");
	return _points[index];
}

int PolygonalChain::GetNumberOfPoints() const
{
	return _pointsCount;
}

float PolygonalChain::GetPerimeter() const
{
	float result = 0;
	for (int i = 1; i < _pointsCount; i++)
	{
		result += _points[i].GetDistance(_points[i - 1]);
	}
	return result;
}
