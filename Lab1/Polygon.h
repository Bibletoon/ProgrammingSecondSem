#pragma once
#include "ClosedPolygonalChain.h"

class Polygon : public ClosedPolygonalChain
{
public:
	Polygon(int pointsCount, Point* points);
	Polygon(const Polygon& polygon);
	~Polygon();
	Polygon& operator = (Polygon const& polygon);
	float GetArea() const;
protected:
	virtual bool _checkValid();
};
