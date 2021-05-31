#pragma once
#include "Cube.h"

class GeneticAlgorithmUnit
{
public:
	GeneticAlgorithmUnit()
	{
	};
	~GeneticAlgorithmUnit();
	GeneticAlgorithmUnit(Cube cube);

	GeneticAlgorithmUnit(const GeneticAlgorithmUnit& unit) : _commands(unit._commands), _cube(unit._cube)
	{
	};
	void DoRandomMoves();
	void ExecuteCommand(std::string command);
	Cube GetCube();
	int GetFitness();
	std::string GetCommands();
private:
	std::string _commands;
	Cube _cube;
};
