#pragma once
#include "Cube.h"
#include "GeneticAlgorithmUnit.h"

class GeneticAlgorithmSolver
{
public:
	inline static const std::string* Permutations = new std::string[]
	{
		"F' L' B' R' U' R U' B L F R U R' U",
		"F R B L U L' U B' R' F' L' U' L U'",
		"U2 B U2 B' R2 F R' F' U2 F' U2 F R'",
		"U2 R U2 R' F2 L F' L' U2 L' U2 L F'",
		"U' B2 D2 L' F2 D2 B2 R' U'",
		"U B2 D2 R F2 D2 B2 L U",
		"D' R' D R2 U' R B2 L U' L' B2 U R2",
		"D L D' L2 U L' B2 R' U R B2 U' L2",
		"R' U L' U2 R U' L R' U L' U2 R U' L U'",
		"L U' R U2 L' U R' L U' R U2 L' U R' U",
		"F' U B U' F U B' U'",
		"F U' B' U F' U' B U",
		"L' U2 L R' F2 R",
		"R' U2 R L' B2 L",
		"M2 U M2 U2 M2 U M2"
	};
	inline static const std::string* Rotations = new std::string[]
	{
		"x", "x'", "x2",
		"y", "y'", "y2"
	};
	inline static const std::string* Orientations = new std::string[]
	{
		"z", "z'", "z2"
	};
	inline static const int PermutationsCount = 15;

	GeneticAlgorithmSolver(const Cube& cube, int populationSize, int elitismNum, int maxGenerations) :
		_cube(cube), _populationSize(populationSize), _elitismNum(elitismNum), _maxGenerations(maxGenerations),
		_generationNumber(0), _solutionFound(false)
	{
	};

	bool StartSolving();
	Cube GetCube();
	int GetGenerationNumber();
	std::string GetComands();
private:
	void ExecuteRandomPermutation(GeneticAlgorithmUnit& unit);
	void ExecuteRandomRotation(GeneticAlgorithmUnit& unit);
	void ExecuteRandomOrientation(GeneticAlgorithmUnit& unit);
	Cube _cube;
	int _populationSize;
	int _elitismNum;
	int _maxGenerations;
	int _generationNumber;
	std::string _commands;
	bool _solutionFound;
};
