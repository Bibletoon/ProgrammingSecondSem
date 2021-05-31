#include "StringAlgorithms.h"

bool StringAlgorithms::replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

void StringAlgorithms::removeSpaces(std::string& string)
{
	string.erase(std::remove_if(string.begin(), string.end(), std::isspace), string.end());
}

std::vector<std::string> StringAlgorithms::split(std::string s, const std::string& delimiter)
{
	size_t pos = 0;
	std::string token;
	std::vector<std::string> result;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		result.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	result.push_back(s);
	return result;
}
