#pragma once
#include <string>
#include <vector>

static class StringAlgorithms
{
public:
	static bool replace(std::string& str, const std::string& from, const std::string& to);
	static void removeSpaces(std::string& string);
	static std::vector<std::string> split(std::string s, const std::string& delimiter);
};
