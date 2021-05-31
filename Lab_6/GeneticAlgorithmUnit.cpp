#include "GeneticAlgorithmUnit.h"

#include "DefaultCommandManager.h"

GeneticAlgorithmUnit::~GeneticAlgorithmUnit()
{
}

GeneticAlgorithmUnit::GeneticAlgorithmUnit(Cube cube) : _cube(cube)
{
}

void GeneticAlgorithmUnit::DoRandomMoves()
{
	for (int i = 0; i < 2; i++)
	{
		SideTypeEnum s = static_cast<SideTypeEnum>(std::rand() % 6);
		int dir = std::rand() % 2;
		int number = std::rand() % 3;
		if (dir == 0)
		{
			_cube.SpinSideForward(s, number, 1);
		}
		else
		{
			_cube.SpinSideBackward(s, number, 1);
		}

		std::string command;
		switch (s)
		{
		case XSide:
			if (number == 0)
			{
				command += "L";
			}
			else if (number == 1)
			{
				command += "M";
			}
			else if (number == 2)
			{
				command += "R";
			}
			break;
		case YSide:
			if (number == 0)
			{
				command += "U";
			}
			else if (number == 1)
			{
				command += "E";
			}
			else if (number == 2)
			{
				command += "D";
			}
			break;
		case ZSide:
			if (number == 0)
			{
				command += "F";
			}
			else if (number == 1)
			{
				command += "S";
			}
			else if (number == 2)
			{
				command += "B";
			}
		}
		if (dir == 1)
		{
			command += "'";
		}
		_commands += command + " ";
	}
}

void GeneticAlgorithmUnit::ExecuteCommand(std::string command)
{
	DefaultCommandManager::ApplyCommands(_cube, command);
	_commands += command + " ";
}

Cube GeneticAlgorithmUnit::GetCube()
{
	return _cube;
}

int GeneticAlgorithmUnit::GetFitness()
{
	return _cube.GetFitness();
}

std::string GeneticAlgorithmUnit::GetCommands()
{
	return _commands;
}
