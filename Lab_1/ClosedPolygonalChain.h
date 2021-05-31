#pragma once
#include "PolygonalChain.h"

class ClosedPolygonalChain : public PolygonalChain
{
public:
	ClosedPolygonalChain(int pointsCount, Point* points);
	//ClosedPolygonalChain(const ClosedPolygonalChain& polygonalChain);
	~ClosedPolygonalChain();
	ClosedPolygonalChain& operator =(ClosedPolygonalChain const& polygonalChain);

	float GetPerimeter() const override;
};
