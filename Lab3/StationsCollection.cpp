#include "StationsCollection.h"

StationsCollection::StationsCollection()
{
}

StationsCollection::StationsCollection(std::string label) : _label(label)
{
}

std::string StationsCollection::getLabel() const
{
	return _label;
}

int StationsCollection::getStationsCount() const
{
	return _stations.size();
}

void StationsCollection::addStation(const TransportStation& station)
{
	_stations.push_back(station);
}
