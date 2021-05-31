#include "Route.h"
#include <cmath>
#include <algorithm>
#include <numeric>

Route::Route() : StationsCollection(), _type()
{
}

Route::Route(std::string label, const TransportType& type) : StationsCollection(label), _type(type)
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
		if (used[i] == true) continue;
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
	bool* used = new bool[_stations.size()];
	for (int i = 0; i < _stations.size(); i++)
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
	while (!std::all_of(used, used + _stations.size(), [](bool i) { return i; }))
	{
		nearestToOne = getNearestPointIndex(indexOne, used, distanceToOne);
		nearestToTwo = getNearestPointIndex(indexTwo, used, distanceToTwo);
		if (distanceToOne < distanceToTwo)
		{
			indexOne = nearestToOne;
			length += distanceToOne;
			used[indexOne] = true;
		}
		else
		{
			indexTwo = nearestToTwo;
			length += distanceToTwo;
			used[indexTwo] = true;
		}
	}
	return length;
	/*int n = _stations.size();
	
	float** distance = new float* [n];

	for (int i=0;i<n;i++)
	{
		distance[i] = new float[n];
	}
	
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			distance[i][j] = _stations[i].getDistance(_stations[j]);
		}
	}
	bool* used = new bool[n];
	for (int i=0;i<n;i++)
	{
		used[i] = false;
	}

	float* curMinDist = new float[n];
	for (int i=0; i<n;i++)
	{
		curMinDist[i] = 1e20;
	}

	curMinDist[0] = 0;
	
	for (int i=0;i<n;i++)
	{
		int f = -1;
		for (int j=0; j<n;j++)
		{
			if (!used[j] && (f==-1 || curMinDist[f] > curMinDist[j]))
			{
				f = j;
			}
		}

		used[f] = true;

		for (int j=0;j<n;j++)
		{
			if (!used[j] && distance[f][j] < curMinDist[j])
			{
				curMinDist[j] = distance[f][j];
			}
		}
	}

	float res = std::accumulate(curMinDist, curMinDist + n, 0);

	delete[] distance;
	delete[] curMinDist;
	delete[] used;
	
	return res;*/
}
