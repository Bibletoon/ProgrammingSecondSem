#include "Cube.h"
#include <array>
#include <stdexcept>

Cube::Cube()
{
}

Cube::Cube(std::array<CubeSide, 6> sides) : _front(sides[2]), _back(sides[4]), _up(sides[0]), _down(sides[5]),
                                            _right(sides[3]), _left(sides[1])
{
}

Cube::Cube(const Cube& cube) : _front(cube._front), _back(cube._back), _up(cube._up), _down(cube._down),
                               _right(cube._right), _left(cube._left)
{
}

Cube::~Cube() = default;

CubeSide& Cube::GetSide(int index)
{
	switch (index)
	{
	case 0:
		return _up;
	case 1:
		return _left;
	case 2:
		return _front;
	case 3:
		return _right;
	case 4:
		return _back;
	case 5:
		return _down;
	default:
		throw std::out_of_range("Wrong index.");
	}
}

CubeSide Cube::GetSide(int index) const
{
	switch (index)
	{
	case 0:
		return _up;
	case 1:
		return _left;
	case 2:
		return _front;
	case 3:
		return _right;
	case 4:
		return _back;
	case 5:
		return _down;
	default:
		throw std::out_of_range("Wrong index.");
	}
}

std::string Cube::ToString() const
{
	std::string result;
	for (int i = 0; i < 3; i++)
	{
		result += std::string(3, ' ') + _up.ToStringArray()[i] + "\n";
	}

	for (int i = 0; i < 3; i++)
	{
		result += _left.ToStringArray()[i] + _front.ToStringArray()[i] + _right.ToStringArray()[i] + _back.
			ToStringArray()[i] + "\n";
	}

	for (int i = 0; i < 3; i++)
	{
		result += std::string(3, ' ') + _down.ToStringArray()[i] + "\n";
	}

	return result;
}


int Cube::GetFitness() const
{
	int fitness = 0;
	for (int i = 0; i < 6; i++)
	{
		Color sideColor = GetSide(i).GetRow((3 - 1) / 2)[(3 - 1) / 2];
		for (int j = 0; j < 3; j++)
		{
			std::array<Color, 3> line = GetSide(i).GetRow(j);
			for (int k = 0; k < 3; k++)
			{
				if (line[k] != sideColor)
				{
					fitness++;
				}
			}
		}
	}
	return fitness;
}

std::string Cube::Scramble()
{
	int count = (std::rand() % 10) + 20;
	std::string commands;
	for (int i = 0; i < count; i++)
	{
		int edjeNumber = std::rand() % 3;
		SideTypeEnum side = static_cast<SideTypeEnum>(std::rand() % 3);
		int times = (std::rand() % 2) + 1;
		int direction = std::rand() % 2;
		if (direction == 0)
		{
			SpinSideForward(side, edjeNumber, times);
		}
		else
		{
			SpinSideBackward(side, edjeNumber, times);
		}
		std::string command;
		switch (side)
		{
		case XSide:
			if (edjeNumber == 0)
			{
				command += "L";
			}
			else if (edjeNumber == 1)
			{
				command += "M";
			}
			else if (edjeNumber == 2)
			{
				command += "R";
			}
			break;
		case YSide:
			if (edjeNumber == 0)
			{
				command += "U";
			}
			else if (edjeNumber == 1)
			{
				command += "E";
			}
			else if (edjeNumber == 2)
			{
				command += "D";
			}
			break;
		case ZSide:
			if (edjeNumber == 0)
			{
				command += "F";
			}
			else if (edjeNumber == 1)
			{
				command += "S";
			}
			else if (edjeNumber == 2)
			{
				command += "B";
			}
		}
		if (direction == 1)
		{
			command += "'";
		}
		for (int j = 0; j < times; j++)
		{
			commands += command + " ";
		}
	}
	return commands;
}

bool Cube::CheckValid() const
{
	int count[6];
	for (int i = 0; i < 6; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::array<Color, 3> line = GetSide(i).GetRow(j);
			for (int k = 0; k < 3; k++)
			{
				count[line[k]] += 1;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (count[i] != 9) return false;
	}
	return true;
}

void Cube::SpinSideForward(SideTypeEnum side, int number, int times)
{
	if (side == XSide)
	{
		if (number < 2)
		{
			if (number == 0)
			{
				_left.SpinForward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetColumn(number);
				line = _down.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _back.SwapColumn(2 - number, line);
				std::reverse(line.begin(), line.end());
				line = _up.SwapColumn(number, line);
				_front.SetColumn(number, line);
			}
		}
		else
		{
			_right.SpinForward(times);
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetColumn(number);
				line = _up.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _back.SwapColumn(2 - number, line);
				std::reverse(line.begin(), line.end());
				line = _down.SwapColumn(number, line);
				_front.SetColumn(number, line);
			}
		}
	}
	else if (side == YSide)
	{
		if (number == 0)
		{
			_up.SpinForward(times);
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetRow(number);
				line = _left.SwapRow(number, line);
				line = _back.SwapRow(number, line);
				line = _right.SwapRow(number, line);
				_front.SetRow(number, line);
			}
		}
		else
		{
			if (number == 2)
			{
				_down.SpinForward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetRow(number);
				line = _right.SwapRow(number, line);
				line = _back.SwapRow(number, line);
				line = _left.SwapRow(number, line);
				_front.SetRow(number, line);
			}
		}
	}
	else if (side == ZSide)
	{
		if (number < 2)
		{
			if (number == 0)
			{
				_front.SpinForward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _left.GetColumn(2 - number);
				std::reverse(line.begin(), line.end());
				line = _up.SwapRow(2 - number, line);
				line = _right.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _down.SwapRow(number, line);
				_left.SetColumn(2 - number, line);
			}
		}
		else
		{
			_back.SpinForward(times);
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _left.GetColumn(2 - number);
				line = _down.SwapRow(number, line);
				std::reverse(line.begin(), line.end());
				line = _right.SwapColumn(number, line);
				line = _up.SwapRow(2 - number, line);
				std::reverse(line.begin(), line.end());
				_left.SetColumn(2 - number, line);
			}
		}
	}
}

void Cube::SpinSideBackward(SideTypeEnum side, int number, int times)
{
	if (side == XSide)
	{
		if (number < 2)
		{
			if (number == 0)
			{
				_left.SpinBackward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetColumn(number);
				line = _up.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _back.SwapColumn(2 - number, line);
				std::reverse(line.begin(), line.end());
				line = _down.SwapColumn(number, line);
				_front.SetColumn(number, line);
			}
		}
		else
		{
			_right.SpinBackward(times);
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetColumn(number);
				line = _down.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _back.SwapColumn(2 - number, line);
				std::reverse(line.begin(), line.end());
				line = _up.SwapColumn(number, line);
				_front.SetColumn(number, line);
			}
		}
	}
	else if (side == YSide)
	{
		if (number == 0)
		{
			_up.SpinBackward(times);
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetRow(number);
				line = _right.SwapRow(number, line);
				line = _back.SwapRow(number, line);
				line = _left.SwapRow(number, line);
				_front.SetRow(number, line);
			}
		}
		else
		{
			if (number == 2)
			{
				_down.SpinBackward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _front.GetRow(number);
				line = _left.SwapRow(number, line);
				line = _back.SwapRow(number, line);
				line = _right.SwapRow(number, line);
				_front.SetRow(number, line);
			}
		}
	}
	else if (side == ZSide)
	{
		if (number < 2)
		{
			if (number == 0)
			{
				_front.SpinBackward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _left.GetColumn(2 - number);
				line = _down.SwapRow(number, line);
				std::reverse(line.begin(), line.end());
				line = _right.SwapColumn(number, line);
				line = _up.SwapRow(2 - number, line);
				std::reverse(line.begin(), line.end());
				_left.SetColumn(2 - number, line);
			}
		}
		else
		{
			if (number == 2)
			{
				_back.SpinBackward(times);
			}
			for (int i = 0; i < times; i++)
			{
				std::array<Color, 3> line = _left.GetColumn(2 - number);
				std::reverse(line.begin(), line.end());
				line = _up.SwapRow(2 - number, line);
				line = _right.SwapColumn(number, line);
				std::reverse(line.begin(), line.end());
				line = _down.SwapRow(number, line);
				_left.SetColumn(2 - number, line);
			}
		}
	}
}

void Cube::SpinCubeForward(CubeRotateDirectionEnum direction, int times)
{
	if (direction == XDirection)
	{
		SpinSideForward(XSide, 2, times);
		SpinSideBackward(XSide, 0, times);
		SpinSideBackward(XSide, 1, times);
	}
	else if (direction == YDirection)
	{
		SpinSideForward(YSide, 0, times);
		SpinSideBackward(YSide, 1, times);
		SpinSideBackward(YSide, 2, times);
	}
	else if (direction == ZDirection)
	{
		SpinSideForward(ZSide, 0, times);
		SpinSideForward(ZSide, 1, times);
		SpinSideBackward(ZSide, 2, times);
	}
}

void Cube::SpinCubeBackward(CubeRotateDirectionEnum direction, int times)
{
	if (direction == XDirection)
	{
		SpinSideBackward(XSide, 2, times);
		SpinSideForward(XSide, 0, times);
		SpinSideForward(XSide, 1, times);
	}
	else if (direction == YDirection)
	{
		SpinSideBackward(YSide, 0, times);
		SpinSideForward(YSide, 1, times);
		SpinSideForward(YSide, 2, times);
	}
	else if (direction == ZDirection)
	{
		SpinSideBackward(ZSide, 0, times);
		SpinSideBackward(ZSide, 1, times);
		SpinSideForward(ZSide, 2, times);
	}
}
