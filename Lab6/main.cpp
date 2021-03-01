#include <iostream>
#include <stdio.h>

#include "Cube.h"
#include "IOManager.h"

int main()
{
	Cube cube = IOManager::ReadCube("cube.txt", 3);
	cube.SpinSideForward(SideEnum::Right, 1);
	std::cout << cube.ToString();
	cube.SpinSideForward(SideEnum::Up, 1);
	std::cout << cube.ToString();
	cube.SpinSideForward(SideEnum::Back, 1);
	std::cout << cube.ToString();
	cube.SpinSideForward(SideEnum::Left, 1);

	std::cout << cube.ToString();
}
