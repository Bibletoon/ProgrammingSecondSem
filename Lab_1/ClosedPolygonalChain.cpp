#include "ClosedPolygonalChain.h"

#include <iostream>

ClosedPolygonalChain::ClosedPolygonalChain(int pointsCount, Point* points) : PolygonalChain(pointsCount, points)
{
}

//ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain& polygonalChain) : PolygonalChain(polygonalChain)
//{
//}

ClosedPolygonalChain::~ClosedPolygonalChain()
{
}

ClosedPolygonalChain& ClosedPolygonalChain::operator=(ClosedPolygonalChain const& polygonalChain)
{
	_pointsCount = polygonalChain._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = polygonalChain._points[i];
	}
	return *this;
}

float ClosedPolygonalChain::GetPerimeter() const
{
	float result = 0;
	for (int i = 1; i < _pointsCount; i++)
	{
		result += _points[i].GetDistance(_points[i - 1]);
	}
	result += _points[0].GetDistance(_points[_pointsCount - 1]);
	return result;
}
