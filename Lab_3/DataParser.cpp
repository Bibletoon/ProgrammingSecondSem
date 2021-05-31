#include "DataParser.h"

#include <algorithm>
#include <iostream>
#include <pugixml.hpp>

#include "StringAlgorithms.h"

void DataParser::fixStreetNames(std::string& name)
{
	std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });
	StringAlgorithms::replace(name, "пр.", "проспект");
	StringAlgorithms::replace(name, "ул.", "улица");
}

bool DataParser::ParseData(const std::string& filename, std::unordered_map<std::string, StationsCollection>& streetsMap,
                           std::unordered_map<std::string, Route>& routesMap)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_file("data.xml");

	if (!res)
	{
		std::cout << "Err";
		return false;
	}
	for (pugi::xml_node node : doc.child("dataset"))
	{
		std::string location = node.child("location").first_child().value();
		StringAlgorithms::removeSpaces(location);
		std::vector<std::string> locations = StringAlgorithms::split(location, ",");
		for (auto i : locations)
		{
			fixStreetNames(i);
		}
		std::string typeOfVencile = node.child("type_of_vehicle").first_child().value();
		std::string name = node.child("the_official_name").first_child().value();
		std::string routesString = node.child("routes").first_child().value();
		std::vector<std::string> routesRaw = StringAlgorithms::split(routesString, ",");
		std::vector<std::string> routes;
		for (std::string str : routesRaw)
		{
			for (std::string route : StringAlgorithms::split(str, "."))
			{
				routes.push_back(route);
			}
		}
		std::string coordinatesString = node.child("coordinates").first_child().value();
		std::vector<std::string> coordinates = StringAlgorithms::split(coordinatesString, ",");

		TransportType type = Tram;
		if (typeOfVencile.compare("Автобус") == 0)
		{
			type = Autobus;
		}
		else if (typeOfVencile.compare("Троллейбус") == 0)
		{
			type = Trolleybus;
		}
		StringAlgorithms::replace(coordinates[0], ".", ",");
		StringAlgorithms::replace(coordinates[1], ".", ",");
		float coordinateX = std::stof(coordinates[0]);
		float coordinateY = std::stof(coordinates[1]);

		TransportStation station(name, coordinateX, coordinateY);

		for (auto str : locations)
		{
			if (!streetsMap.contains(str))
			{
				StationsCollection newStreet(str);
				newStreet.addStation(station);
				streetsMap.insert(std::make_pair(str, newStreet));
			}
			else
			{
				streetsMap[str].addStation(station);
			}
		}

		for (auto route : routes)
		{
			std::string routeKey;
			switch (type)
			{
			case Autobus:
				routeKey = "A" + route;
				break;
			case Trolleybus:
				routeKey = "B" + route;
				break;
			case Tram:
				routeKey = "C" + route;
				break;
			}
			if (!routesMap.contains(routeKey))
			{
				Route newRoute(route, type);
				newRoute.addStation(station);
				routesMap.insert(std::make_pair(routeKey, newRoute));
			}
			else
			{
				routesMap[routeKey].addStation(station);
			}
		}
	}

	return true;
}
