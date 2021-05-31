#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Cube.h"
#include "DefaultCommandManager.h"
#include "GeneticAlgorithmSolver.h"
#include "IOManager.h"

int main()
{
	//ATTENTION: Program using genetic algorithm, it might take up to 10 minutes to solve cube. Average solving time ~3 min
	std::srand(time(nullptr));

	Cube cube = IOManager::ReadCube("cube.txt");
	//DefaultCommandManager::ApplyCommands(cube, "D' B2 D2 L2 U' L R' F L2 R2 U' L2 B' L D' B2 R2 B' R F U2 R B2 F' L' B2 L2 R F2 L'");
	std::cout << cube.Scramble() << std::endl;
	int maxWorldsCount = 50;

	std::cout << cube.ToString();

	std::string solveCommands;
#pragma omp parallel
	{
#pragma omp for
		for (int worldCounter = 1; worldCounter <= maxWorldsCount; worldCounter++)
		{
			std::cout << "Starting world: " << worldCounter << std::endl;
			GeneticAlgorithmSolver s(cube, 1000, 200, 200);
			bool res = s.StartSolving();
			if (res)
			{
				std::cout << "Solved in world" << worldCounter << std::endl;
				std::cout << s.GetComands();
				IOManager::SaveCube(cube, "result.txt");
				exit(0);
			}
			std::cout << "Finished world " << worldCounter << std::endl;
		}
	}
	return 0;
}
