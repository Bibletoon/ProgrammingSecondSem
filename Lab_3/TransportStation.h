#pragma once
#include <string>

class TransportStation
{
public:
	TransportStation(std::string name, float x, float y) : _name(name), _coordinateX(x), _coordinateY(y)
	{
	};
	float getX() const;
	float getY() const;
	std::string getName() const;
	float getDistance(const TransportStation& station) const;
private:
	std::string _name;
	float _coordinateX;
	float _coordinateY;
};
