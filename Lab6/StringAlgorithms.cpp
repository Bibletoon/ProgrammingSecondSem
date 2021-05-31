#include "StringAlgorithms.h"

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
