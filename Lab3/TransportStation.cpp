#include "TransportStation.h"
#include <cmath>

float TransportStation::getY() const
{
	return _coordinateY;
}

float TransportStation::getX() const
{
	return _coordinateX;
}

std::string TransportStation::getName() const
{
	return _name;
}


float TransportStation::getDistance(const TransportStation& station) const
{
	return std::sqrt((station._coordinateX - _coordinateX) * (station._coordinateY - _coordinateY) + (station._coordinateY - _coordinateY) * (station._coordinateY - _coordinateY));

}

