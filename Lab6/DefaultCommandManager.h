#pragma once
#include "Cube.h"

class DefaultCommandManager
{
public:
	static void ApplyCommands(Cube& cube, std::string commands);
	static std::tuple<SideTypeEnum, int, int> ParseSideCommand(std::string command);
	static std::tuple<CubeRotateDirectionEnum, int> ParseCubeCommand(std::string command);
};
