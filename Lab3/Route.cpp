#include "Route.h"

#include <algorithm>

Route::Route() : StationsCollection()
{
}

Route::Route(std::string label, TransportType type) : StationsCollection(label), _type(type)
{
}

TransportType Route::getType() const
{
	return _type;
}

int Route::getNearestPointIndex(int index, bool* used, float& returnDistance) const
{
	int nearest;
	float distance = 10000;
	for (int i = 0; i < _stations.size(); i++)
	{
		if (used[i]==true) continue;
		float dist = _stations[i].getDistance(_stations[index]);
		if (isnan(dist))
		{
			dist = 0;
		}
		if (dist < distance)
		{
			distance = dist;
			nearest = i;
		}
	}
	returnDistance = distance;
	return nearest;
}

float Route::getLength() const
{
	//_station
	bool* used = new bool[_stations.size()];
	for (int i=0;i<_stations.size();i++)
	{
		used[i] = false;
	}
	int indexOne = 0;
	int indexTwo;
	int nearestToOne;
	int nearestToTwo;
	float length = 0;
	float distanceToOne;
	float distanceToTwo;
	indexTwo = getNearestPointIndex(indexOne, used, distanceToOne);
	used[indexOne] = true;
	used[indexTwo] = true;
	length += distanceToOne;
	while (!std::all_of(used,used+_stations.size(),[](bool i){return i;}))
	{
		nearestToOne = getNearestPointIndex(indexOne,used,distanceToOne);
		nearestToTwo = getNearestPointIndex(indexTwo, used,distanceToTwo);
		if (distanceToOne<distanceToTwo)
		{
			indexOne = nearestToOne;
			length += distanceToOne;
			used[indexOne] = true;
		} else
		{
			indexTwo = nearestToTwo;
			length += distanceToTwo;
			used[indexTwo] = true;
		}
	}
	return length;
}
