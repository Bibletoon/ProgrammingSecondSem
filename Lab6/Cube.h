#pragma once
#include "CubeRotationDirection.h"
#include "CubeSide.h"
#include "SideEnum.h"

class Cube
{
public:
	Cube();
	Cube(CubeSide* sides, int size);

	std::string ToString();
	std::string* ToStringArray();
	
	void SpinSideForward(SideEnum side, int times);
	void SpinSideBackward(SideEnum side, int times);

	void SpinCube(CubeRotateDirectionEnum direction);
private:
	int _size;
	CubeSide _front;
	CubeSide _back;
	CubeSide _up;
	CubeSide _down;
	CubeSide _right;
	CubeSide _left;
	
};
