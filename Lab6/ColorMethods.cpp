#include "ColorMethods.h"
char ColorMethods::ColorToChar(Color color)
{
	switch (color)
	{
	case Color::White:
		return 'W';
	case Color::Yellow:
		return	'Y';
	case Color::Green:
		return 'G';
	case Color::Blue:
		return 'B';
	case Color::Red:
		return 'R';
	case Color::Orange:
		return 'O';
	}
}

Color ColorMethods::CharToColor(char color)
{
	switch (color)
	{
	case 'W':
		return Color::White;
	case 'Y':
		return Color::Yellow;
	case 'G':
		return Color::Green;
	case 'B':
		return Color::Blue;
	case 'R':
		return Color::Red;
	case 'O':
		return Color::Orange;
	}
}