#include "CubeSide.h"

#include "ColorMethods.h"

CubeSide::CubeSide()
{
}

CubeSide::CubeSide(int size, Color** colors)
{
	_size = size;
	_side = new Color * [_size];
	for (int i = 0; i < _size; i++)
	{
		_side[i] = new Color[_size];
		for (int j = 0; j < _size; j++)
		{
			_side[i][j] = colors[i][j];
		}
	}
}



std::string* CubeSide::ToStringArray()
{
	std::string* array = new std::string[_size];
	for (int i=0;i<_size;i++)
	{
		std::string string = "";
		for (int j=0;j<_size;j++)
		{
			string += ColorMethods::ColorToChar(_side[i][j]);
		}
		array[i] = string;
	}

	return array;
}

void CubeSide::SpinForward(int times)
{

	for (int i=0;i<times;i++)
	{
		Color** oldSide = new Color * [_size];
		for (int i=0;i<_size;i++)
		{
			oldSide[i] = GetColumn(i);
			std::reverse(oldSide[i], oldSide[i] + _size);
		}
		for (int i=0;i<_size;i++)
		{
			SetRow(i, oldSide[i]);
		}
	}
}

void CubeSide::SpinBackward(int times)
{
	for (int i=0;i<times;i++)
	{
		Color** oldSide = new Color * [_size];
		for (int i=0;i<_size;i++)
		{
			oldSide[i] = GetColumn(_size - i - 1);
		}
		for (int i=0;i<_size;i++)
		{
			SetRow(i, oldSide[i]);
		}
	}
}

Color* CubeSide::GetRow(int number)
{
	return _side[number];
}

void CubeSide::SetRow(int number, Color* row)
{
	_side[number] = row;
}

Color* CubeSide::SwapRow(int number, Color row[])
{
	Color* oldRow = GetRow(number);
	SetRow(number, row);
	return oldRow;
}

Color* CubeSide::GetColumn(int number)
{
	Color* column = new Color[_size];
	for (int i = 0; i < _size; i++)
	{
		column[i] = _side[i][number];
	}
	return column;
}

void CubeSide::SetColumn(int number, Color* column)
{
	for (int i = 0; i < _size; i++)
	{
		_side[i][number] = column[i];
	}
}

Color* CubeSide::SwapColumn(int number, Color* column)
{
	Color* oldColumn = GetColumn(number);
	SetColumn(number, column);
	return oldColumn;
}
