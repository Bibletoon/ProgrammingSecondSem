#pragma once
#include <string>

#include "Color.h"

class ColorMethods
{
public:
	static std::string ColorToString(const Color& color);
	static Color CharToColor(char color);
};
