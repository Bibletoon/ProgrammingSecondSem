#pragma once
#include <string>

#include "Color.h"

class CubeSide
{
public:
	CubeSide();
	CubeSide(std::array<std::array<Color, 3>, 3> colors);
	CubeSide(const CubeSide& side);
	~CubeSide();
	CubeSide& operator=(const CubeSide& side);
	//std::string ToString() const;
	std::array<std::string, 3> ToStringArray() const;

	void SpinForward(int times);
	void SpinBackward(int times);

	std::array<Color, 3> GetRow(int number);
	void SetRow(int number, std::array<Color, 3> row);
	std::array<Color, 3> SwapRow(int number, std::array<Color, 3> row);
	std::array<Color, 3> GetColumn(int number);
	void SetColumn(int number, std::array<Color, 3> column);
	std::array<Color, 3> SwapColumn(int number, std::array<Color, 3> column);
private:
	Color _side[3][3];
};
