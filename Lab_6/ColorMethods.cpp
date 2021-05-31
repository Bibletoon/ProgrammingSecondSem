#include "ColorMethods.h"

#include <stdexcept>

std::string ColorMethods::ColorToString(const Color& color)
{
	switch (color)
	{
	case White:
		return "W";
	case Yellow:
		return "Y";
	case Green:
		return "G";
	case Blue:
		return "B";
	case Red:
		return "R";
	case Orange:
		return "O";
	default:
		throw std::logic_error("Unsupported color.");
	}
}

Color ColorMethods::CharToColor(char color)
{
	switch (color)
	{
	case 'W':
		return White;
	case 'Y':
		return Yellow;
	case 'G':
		return Green;
	case 'B':
		return Blue;
	case 'R':
		return Red;
	case 'O':
		return Orange;
	default:
		throw std::logic_error("Unsupported color.");
	}
}
