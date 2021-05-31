#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon
{
public:
	RegularPolygon(int pointsCount, Point* points);
	RegularPolygon(const RegularPolygon& regularPolygon);
	~RegularPolygon();
	RegularPolygon& operator =(RegularPolygon const& regularPolygon);
protected:
	bool _checkValid() override;
};
