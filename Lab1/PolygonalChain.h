#pragma once
#include <vector>

#include "Point.h"

class PolygonalChain
{
public:
	PolygonalChain(int pointsCount, Point* points);
	~PolygonalChain();
	PolygonalChain(const PolygonalChain& polygonalChain);
	PolygonalChain& operator = (PolygonalChain const& polygonalChain);
	Point GetPoint(int index) const;
	int GetNumberOfPoints() const;
	virtual float GetPerimeter() const;
protected:
	Point* _points;
	int _pointsCount;
};
