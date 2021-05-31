#include "CubeSide.h"

#include <array>


#include "ColorMethods.h"

CubeSide::CubeSide()
{
}

CubeSide::CubeSide(std::array<std::array<Color, 3>, 3> colors)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_side[i][j] = colors[i][j];
		}
	}
}

CubeSide::CubeSide(const CubeSide& side)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_side[i][j] = side._side[i][j];
		}
	}
}

CubeSide::~CubeSide()
{
}

CubeSide& CubeSide::operator=(const CubeSide& side)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_side[i][j] = side._side[i][j];
		}
	}
	return *this;
}


std::array<std::string, 3> CubeSide::ToStringArray() const
{
	std::array<std::string, 3> array;
	for (int i = 0; i < 3; i++)
	{
		std::string string;
		for (int j = 0; j < 3; j++)
		{
			string += ColorMethods::ColorToString(_side[i][j]);
		}
		array[i] = string;
	}

	return array;
}

void CubeSide::SpinForward(int times)
{
	for (int i = 0; i < times; i++)
	{
		Color newSide[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newSide[i][j] = _side[2 - j][i];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_side[i][j] = newSide[i][j];
			}
		}
	}
}

void CubeSide::SpinBackward(int times)
{
	for (int i = 0; i < times; i++)
	{
		Color newSide[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newSide[i][j] = _side[j][3 - 1 - i];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_side[i][j] = newSide[i][j];
			}
		}
	}
}

std::array<Color, 3> CubeSide::GetRow(int number)
{
	return std::array<Color, 3>{_side[number][0], _side[number][1], _side[number][2]};
}

void CubeSide::SetRow(int number, std::array<Color, 3> row)
{
	for (int i = 0; i < 3; i++)
	{
		_side[number][i] = row[i];
	}
}

std::array<Color, 3> CubeSide::SwapRow(int number, std::array<Color, 3> row)
{
	std::array<Color, 3> oldRow = GetRow(number);
	SetRow(number, row);
	return oldRow;
}

std::array<Color, 3> CubeSide::GetColumn(int number)
{
	std::array<Color, 3> column;
	for (int i = 0; i < 3; i++)
	{
		column[i] = _side[i][number];
	}
	return column;
}

void CubeSide::SetColumn(int number, std::array<Color, 3> column)
{
	for (int i = 0; i < 3; i++)
	{
		_side[i][number] = column[i];
	}
}

std::array<Color, 3> CubeSide::SwapColumn(int number, std::array<Color, 3> column)
{
	std::array<Color, 3> oldColumn = GetColumn(number);
	SetColumn(number, column);
	return oldColumn;
}
