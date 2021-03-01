#pragma once
#include <string>

#include "Color.h"

class CubeSide
{
public:
	CubeSide();
	CubeSide(int size, Color** colors);

	std::string ToString();
	std::string* ToStringArray();

	void SpinForward(int times);
	void SpinBackward(int times);

	Color* GetRow(int number);
	void SetRow(int number, Color* row);
	Color* SwapRow(int number, Color* row);
	Color* GetColumn(int number);
	void SetColumn(int number, Color* column);
	Color* SwapColumn(int number, Color* column);
private:
	int _size;
	Color** _side;
};
