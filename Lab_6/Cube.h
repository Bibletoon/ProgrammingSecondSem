#pragma once
#include "CubeRotationDirection.h"
#include "CubeSide.h"
#include "SideTypeEnum.h"

class Cube
{
public:
	Cube();
	Cube(std::array<CubeSide, 6>);
	Cube(const Cube& cube);
	~Cube();
	CubeSide& GetSide(int index);
	CubeSide GetSide(int index) const;

	std::string ToString() const;

	int GetFitness() const;
	std::string Scramble();
	bool CheckValid() const;

	void SpinSideForward(SideTypeEnum side, int number, int times);
	void SpinSideBackward(SideTypeEnum side, int number, int times);

	void SpinCubeForward(CubeRotateDirectionEnum direction, int times);
	void SpinCubeBackward(CubeRotateDirectionEnum direction, int times);
private:
	CubeSide _front;
	CubeSide _back;
	CubeSide _up;
	CubeSide _down;
	CubeSide _right;
	CubeSide _left;
};
