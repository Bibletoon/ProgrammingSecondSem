#pragma once
#include <string>
#include <fstream>
#include "Cube.h"

class IOManager
{
public:
	static Cube ReadCube(std::string filename, int size);
private:
	static CubeSide parseSide(std::string* sideStrings, int size);
};
