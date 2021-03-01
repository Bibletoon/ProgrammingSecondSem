#include "Cube.h"

Cube::Cube()
{
}

Cube::Cube(CubeSide* sides, int size)
{
	_up = sides[0];
	_left = sides[1];
	_front = sides[2];
	_right = sides[3];
	_back = sides[4];
	_down = sides[5];
	_size = size;
}

std::string Cube::ToString()
{
	std::string result;
	for (int i=0;i<_size;i++)
	{
		result += std::string(_size,' ')+_up.ToStringArray()[i] + "\n";
	}
	
	for (int i=0;i<_size;i++)
	{
		result += _left.ToStringArray()[i] + _front.ToStringArray()[i] + _right.ToStringArray()[i] + _back.ToStringArray()[i] + "\n";
	}
	
	for (int i=0;i<_size;i++)
	{
		result += std::string(_size, ' ') + _down.ToStringArray()[i] + "\n";
	}
	
	return result;
}

void Cube::SpinSideForward(SideEnum side, int times)
{
	if (side == SideEnum::Front)
	{
		_front.SpinForward(times);
		for (int i=0;i<times;i++)
		{
			Color* line = _left.GetColumn(_size-1);
			line = _up.SwapRow(_size-1, line);
			line = _right.SwapColumn(0, line);
			line = _down.SwapRow(0, line);
			_left.SetColumn(_size-1, line);
		}
	} else if (side == SideEnum::Back) {
		_back.SpinForward(times);
		for (int i=0;i<times;i++)
		{
			Color* line = _left.GetColumn(0);
			line = _down.SwapRow(_size - 1,line);
			line = _right.SwapColumn(_size - 1, line);
			_up.SwapRow(0, line);
			_left.SetColumn(0, line);
		}
	} else if (side == SideEnum::Left)
	{
		_left.SpinForward(times);
		for (int i=0;i<_size;i++)
		{
			Color* line = _front.GetColumn(0);
			line = _down.SwapColumn(0, line);
			line = _back.SwapColumn(0, line);
			line = _up.SwapColumn(0, line);
			_front.SetColumn(0, line);
		}
	} else if (side == SideEnum::Right)
	{
		for (int i=0;i<_size;i++)
		{
			Color* line = _front.GetColumn(_size - 1);
			line = _up.SwapColumn(_size - 1,line);
			line = _back.SwapColumn(_size - 1,line);
			line = _down.SwapColumn(_size - 1, line);
			_front.SetColumn(_size - 1, line);
		}
	} else if (side == SideEnum::Up)
	{
		_up.SpinForward(times);
		for (int i=0;i<times;i++)
		{
			Color* line = _front.GetRow(0);
			line = _left.SwapRow(0, line);
			line = _back.SwapRow(0, line);
			line = _right.SwapRow(0, line);
			_front.SetRow(0, line);
		}
	} else if (side==SideEnum::Down)
	{
		_down.SpinForward(times);
		for (int i=0;i<times;i++)
		{
			Color* line = _front.GetRow(_size - 1);
			line = _right.SwapRow(_size - 1, line);
			line = _back.SwapRow(_size - 1,line);
			line = _left.SwapRow(_size - 1,line);
			_front.SetRow(_size-1,line);
		}
	}

}
