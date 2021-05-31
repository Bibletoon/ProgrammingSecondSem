#pragma once
#include <string>
#include <fstream>
#include "Cube.h"

class IOManager
{
public:
	static Cube ReadCube(std::string filename);
	static void SaveCube(const Cube& cube, std::string filename);
private:
	static CubeSide parseSide(std::string* sideStrings);
};
