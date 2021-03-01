#pragma once
#include <tuple>

class Point
{
public:
	Point();
	~Point();
	Point(float x, float y);
	Point(const Point& point);
	Point& operator = (const Point& point);
	float GetX() const;
	float GetY() const;
	std::tuple<int, int> GetCoordinates() const;
	void SetX(float x);
	void SetY(float y);
	void SetCoordinates(float x, float y);
	float GetDistance(const Point& point) const;
private:
	float _x;
	float _y;
};
