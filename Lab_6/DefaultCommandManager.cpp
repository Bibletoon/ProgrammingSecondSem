#include "DefaultCommandManager.h"
#include "StringAlgorithms.h"
#include <vector>

void DefaultCommandManager::ApplyCommands(Cube& cube, std::string commands)
{
	std::vector<std::string> commandsList = StringAlgorithms::split(commands, " ");

	for (auto command : commandsList)
	{
		if (std::tolower(command[0]) == command[0])
		{
			auto res = ParseCubeCommand(command);
			CubeRotateDirectionEnum direction = std::get<0>(res);
			int number = std::get<1>(res);
			if (number < 0)
			{
				cube.SpinCubeBackward(direction, 1);
			}
			else
			{
				cube.SpinCubeForward(direction, number);
			}
		}
		else
		{
			auto res = ParseSideCommand(command);
			SideTypeEnum side = std::get<0>(res);
			int number = std::get<1>(res);
			int helper = std::get<2>(res);
			if (helper < 0)
			{
				cube.SpinSideBackward(side, number, abs(helper));
			}
			else
			{
				cube.SpinSideForward(side, number, helper);
			}
		}
	}
}

std::tuple<SideTypeEnum, int, int> DefaultCommandManager::ParseSideCommand(std::string command)
{
	SideTypeEnum side;
	int number;
	switch (command[0])
	{
	case 'F':
		side = ZSide;
		number = 0;
		break;
	case 'B':
		side = ZSide;
		number = 2;
		break;
	case 'S':
		side = ZSide;
		number = 1;
		break;
	case 'U':
		side = YSide;
		number = 0;
		break;
	case 'D':
		side = YSide;
		number = 2;
		break;
	case 'E':
		side = YSide;
		number = 1;
		break;
	case 'L':
		side = XSide;
		number = 0;
		break;
	case 'R':
		side = XSide;
		number = 2;
		break;
	case 'M':
		side = XSide;
		number = 1;
		break;
	}

	int secondNum = 1;

	if (command.size() == 2)
	{
		if (command[1] == '\'')
		{
			secondNum = -1;
		}
		else if (command[1] == '2')
		{
			secondNum = 2;
		}
	}
	return std::make_tuple(side, number, secondNum);
}

std::tuple<CubeRotateDirectionEnum, int> DefaultCommandManager::ParseCubeCommand(std::string command)
{
	CubeRotateDirectionEnum direction;

	switch (command[0])
	{
	case 'x':
		direction = XDirection;
		break;
	case 'y':
		direction = YDirection;
		break;
	case 'z':
		direction = ZDirection;
		break;
	}

	int number = 1;

	if (command.size() == 2)
	{
		if (command[1] == '\'')
		{
			number = -1;
		}
		else if (command[1] == '2')
		{
			number = 2;
		}
	}
	return std::make_tuple(direction, number);
}
