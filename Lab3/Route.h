#pragma once
#include "StationsCollection.h"
#include "TransportType.h"

class Route : public StationsCollection
{
public:
	Route();
	Route(std::string label, const TransportType& type);
	TransportType getType() const;
	float getLength() const;
private:
	TransportType _type;
	int getNearestPointIndex(int index, bool* used, float& returnDistance) const;
};
