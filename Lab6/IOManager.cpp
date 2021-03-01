#include "IOManager.h"

#include "IOManager.h"

#include "ColorMethods.h"

Cube IOManager::ReadCube(std::string filename, int size)
{
	std::ifstream fin(filename);
	CubeSide* sides = new CubeSide[6];

	std::string sideString;
	std::string* sideStrings = new std::string[size];
	std::string* sideStringsRaw = new std::string[size];
	
	for (int i=0;i<size;i++)
	{
		fin >> sideString;
		sideStrings[i] = sideString;
	}
	sides[0] = parseSide(sideStrings, size);

	for (int i=0;i<size;i++)
	{
		fin >> sideString;
		sideStringsRaw[i] = sideString;
	}

	for (int i=1;i<5;i++)
	{
		for (int j=0;j<size;j++)
		{
			sideStrings[j] = sideStringsRaw[j].substr(0, size);
			sideStringsRaw[j] = sideStringsRaw[j].erase(0, size);
		}
		sides[i] = parseSide(sideStrings, size);
	}

	for (int i = 0; i < size; i++)
	{
		fin >> sideString;
		sideStrings[i] = sideString;
	}
	sides[5] = parseSide(sideStrings, size);
	fin.close();
	return Cube(sides, size);
}

CubeSide IOManager::parseSide(std::string* sideStrings, int size)
{
	Color** curSideColors = new Color * [size];
	for (int i=0;i<size;i++)
	{
		Color* row = new Color[size];
		for (int j = 0; j < size; j++)
		{
			row[j] = ColorMethods::CharToColor(sideStrings[i][j]);
		}
		curSideColors[i] = row;
	}
	return CubeSide(size, curSideColors);
}
