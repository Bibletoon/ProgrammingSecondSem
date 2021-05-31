#pragma once
#include <string>
#include <unordered_map>

#include "Route.h"
#include "StationsCollection.h"

static class DataParser
{
public:
	static bool ParseData(const std::string& filename, std::unordered_map<std::string, StationsCollection>& streetsMap,
	                      std::unordered_map<std::string, Route>& routesMap);
private:
	static void fixStreetNames(std::string& name);
};
