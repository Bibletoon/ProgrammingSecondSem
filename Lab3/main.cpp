#include <iostream>
#include <unordered_map>

#include "DataParser.h"
#include "Route.h"
#include "StationsCollection.h"

int main()
{
	setlocale(0, "");
	std::unordered_map<std::string, StationsCollection> streetsMap;
	std::unordered_map<std::string, Route> routesMap;
	
	bool res = DataParser::ParseData("data.xml", streetsMap, routesMap);

	if (!res)
	{
		std::cout << "Data parsing error occured";
		return -1;
	}
	
	int* routeMaxStops = new int[3]{0,0,0};
	std::string* routeMaxStopsNames = new std::string[3];
	for (auto i : routesMap)
	{
		int index = i.second.getType();
		if (routeMaxStops[index] < i.second.getStationsCount())
		{
			routeMaxStops[index] = i.second.getStationsCount();
			routeMaxStopsNames[index] = i.second.getLabel();
		}
	}

	int streetMaxStops = 0;
	std::string streetMaxStopsName;
	for (auto i: streetsMap)
	{
		if (i.second.getStationsCount()>streetMaxStops && i.first!="")
		{
			streetMaxStops = i.second.getStationsCount();
			streetMaxStopsName = i.first;
		}
	}

	float maxLength = 0;
	std::string maxRouteName;
	for (auto i:routesMap)
	{
		float length = i.second.getLength();
		if (length>maxLength)
		{
			maxLength = length;
			maxRouteName = i.second.getLabel();
		}
	}
	
	std::cout << "Maximal autobus route - " << routeMaxStopsNames[0] << " Stops count - " << routeMaxStops[0] << std::endl;
	std::cout << "Maximal trolleybus route " << routeMaxStopsNames[1] << " Stops count - " << routeMaxStops[1] << std::endl;
	std::cout << "Maximal tram route " << routeMaxStopsNames[2] << " Stops count - "<< routeMaxStops[2] << std::endl;
	std::cout << "Street with maximum stops " << streetMaxStopsName << " Stops count - " << streetMaxStops << std::endl;
	std::cout << "Route with maximal length " << maxRouteName << " Length - " << maxLength << std::endl;
}