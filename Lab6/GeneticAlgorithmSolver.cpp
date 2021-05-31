#include "GeneticAlgorithmSolver.h"

#include <algorithm>
#include <vector>
#include <iomanip>
#include "GeneticAlgorithmUnit.h"

bool GeneticAlgorithmSolver::StartSolving()
{
	std::vector<GeneticAlgorithmUnit> units;
	_solutionFound = false;
	for (int i = 0; i < _populationSize; i++)
	{
		GeneticAlgorithmUnit unit(_cube);
		unit.DoRandomMoves();
		units.push_back(unit);
	}
	for (; _generationNumber < _maxGenerations; _generationNumber++)
	{
		std::sort(units.begin(), units.end(), [](GeneticAlgorithmUnit a, GeneticAlgorithmUnit b)-> bool
		{
			return a.GetFitness() < b.GetFitness();
		});
		for (int i = 0; i < _populationSize; i++)
		{
			if (units[i].GetFitness() == 0)
			{
				_cube = units[i].GetCube();
				_commands = units[i].GetCommands();
				_solutionFound = true;
				break;
			}

			if (i > _elitismNum)
			{
				int index = std::rand() % _elitismNum;
				units[i] = GeneticAlgorithmUnit(units[index]);
				int evolutionType = std::rand() % 6;

				if (evolutionType == 0)
				{
					ExecuteRandomPermutation(units[i]);
				}
				else if (evolutionType == 1)
				{
					ExecuteRandomPermutation(units[i]);
					ExecuteRandomPermutation(units[i]);
				}
				else if (evolutionType == 2)
				{
					ExecuteRandomRotation(units[i]);
					ExecuteRandomPermutation(units[i]);
				}
				else if (evolutionType == 3)
				{
					ExecuteRandomOrientation(units[i]);
					ExecuteRandomPermutation(units[i]);
				}
				else if (evolutionType == 4)
				{
					ExecuteRandomRotation(units[i]);
					ExecuteRandomOrientation(units[i]);
					ExecuteRandomRotation(units[i]);
				}
				else if (evolutionType == 5)
				{
					ExecuteRandomOrientation(units[i]);
					ExecuteRandomRotation(units[i]);
					ExecuteRandomRotation(units[i]);
				}
			}
		}
	}
	if (_solutionFound) return true;

	_cube = units[0].GetCube();
	_commands = units[0].GetCommands();
	return false;
}

Cube GeneticAlgorithmSolver::GetCube()
{
	return _cube;
}

int GeneticAlgorithmSolver::GetGenerationNumber()
{
	return _generationNumber;
}

std::string GeneticAlgorithmSolver::GetComands()
{
	return _commands;
}

void GeneticAlgorithmSolver::ExecuteRandomPermutation(GeneticAlgorithmUnit& unit)
{
	int index = std::rand() % PermutationsCount;
	unit.ExecuteCommand(Permutations[index]);
}

void GeneticAlgorithmSolver::ExecuteRandomRotation(GeneticAlgorithmUnit& unit)
{
	int index = std::rand() % 6;
	unit.ExecuteCommand(Rotations[index]);
}

void GeneticAlgorithmSolver::ExecuteRandomOrientation(GeneticAlgorithmUnit& unit)
{
	int index = std::rand() % 3;
	unit.ExecuteCommand(Orientations[index]);
}
