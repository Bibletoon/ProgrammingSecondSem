#include "IOManager.h"

#include <array>

#include "ColorMethods.h"

Cube IOManager::ReadCube(std::string filename)
{
	std::ifstream fin(filename);
	std::array<CubeSide, 6> sides;

	std::string sideString;
	std::string sideStrings[3];
	std::string sideStringsRaw[3];

	for (int i = 0; i < 3; i++)
	{
		fin >> sideString;
		sideStrings[i] = sideString;
	}
	sides[0] = parseSide(sideStrings);

	for (int i = 0; i < 3; i++)
	{
		fin >> sideString;
		sideStringsRaw[i] = sideString;
	}

	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sideStrings[j] = sideStringsRaw[j].substr(0, 3);
			sideStringsRaw[j] = sideStringsRaw[j].erase(0, 3);
		}
		sides[i] = parseSide(sideStrings);
	}

	for (int i = 0; i < 3; i++)
	{
		fin >> sideString;
		sideStrings[i] = sideString;
	}
	sides[5] = parseSide(sideStrings);
	fin.close();
	return Cube(sides);
}

void IOManager::SaveCube(const Cube& cube, std::string filename)
{
	std::ofstream fout(filename);
	fout << cube.ToString();
	fout.close();
}

CubeSide IOManager::parseSide(std::string* sideStrings)
{
	std::array<std::array<Color, 3>, 3> curSideColors;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			curSideColors[i][j] = ColorMethods::CharToColor(sideStrings[i][j]);
		}
	}
	return CubeSide(curSideColors);
}
