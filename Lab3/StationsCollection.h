#pragma once
#include <string>
#include <vector>
#include "TransportStation.h"

class StationsCollection
{
public:
	StationsCollection();
	StationsCollection(std::string label);
	std::string getLabel() const;
	int getStationsCount() const;
	void addStation(const TransportStation& station);
protected:
	std::string _label;
	std::vector<TransportStation> _stations;
};
