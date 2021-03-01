#include "Triangle.h"

#include "Vector.h"

Triangle::Triangle(const Point& pointOne, const Point& pointTwo, const Point& pointThree) : Polygon(3, new Point[3]{ pointOne, pointTwo, pointThree })
{
}

Triangle::Triangle(Point* points) : Polygon(3, points)
{
}

Triangle::Triangle(int pointsCount, Point* points) : Polygon(pointsCount, points)
{
}

Triangle::~Triangle()
{
}

Triangle::Triangle(const Triangle& triangle) : Polygon(triangle)
{
}

Triangle& Triangle::operator=(Triangle const& triangle)
{
	_pointsCount = triangle._pointsCount;
	_points = new Point[_pointsCount];
	for (int i = 0; i < _pointsCount; i++)
	{
		_points[i] = triangle._points[i];
	}
	return *this;
}

bool Triangle::IsRight() const
{
	Vector sideOne = Vector(_points[0], _points[1]);
	Vector sideTwo = Vector(_points[1], _points[2]);
	Vector sideThree = Vector(_points[2], _points[0]);

	return (sideOne.GetScalarProduct(sideTwo) == 0 || sideTwo.GetScalarProduct(sideThree) == 0 || sideThree.GetScalarProduct(sideOne) == 0);

}
