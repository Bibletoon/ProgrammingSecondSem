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
	const float p = 0.017453292519943295; // Math.PI / 180
	float a = 0.5 - std::cos((station._coordinateX - _coordinateX) * p) / 2 +
		std::cos(_coordinateX * p) * std::cos(station._coordinateX * p) *
		(1 - std::cos((station._coordinateY - _coordinateY) * p)) / 2;

	return 12742 * std::asin(std::sqrt(a)); // 2 * R; R = 6371 km
	//return std::sqrt((station._coordinateX - _coordinateX) * (station._coordinateY - _coordinateY) + (station._coordinateY - _coordinateY) * (station._coordinateY - _coordinateY));
}
