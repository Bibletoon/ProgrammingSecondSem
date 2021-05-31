#include <iostream>
#include <algorithm>
#include "CircularBuffer.h"
#include "cassert"

void TestOnDouble()
{
	CircularBuffer<double> myBuffer(4);
	myBuffer.pushFront(15);
	assert(myBuffer.getFirst() == 15);
	myBuffer.pushFront(-1.2);
	assert(myBuffer.getFirst() == -1.2);
	myBuffer.pushFront(120);
	assert(myBuffer.getFirst() == 120);
	myBuffer.pushBack(8);
	assert(myBuffer.getLast() == 8);
	myBuffer.pushBack(7.15);
	assert(myBuffer.getLast() == 7.15);

	assert(myBuffer[0] == -1.2);
	assert(myBuffer[3] == 7.15);

	std::sort(myBuffer.ubegin(), myBuffer.uend());

	assert(myBuffer[0] == -1.2);
	assert(myBuffer[3] == 15);
	assert(std::any_of(myBuffer.ubegin(), myBuffer.uend(), [](double el)->bool {return el < 0; })==true);
}

void ShowOnDouble()
{
	CircularBuffer<double> myBuffer(4);
	std::cout << "Initialise new buffer with capacity 4" << std::endl;

	std::cout << "Push front three numbers" << std::endl;
	myBuffer.pushFront(15);
	myBuffer.pushFront(-1.2);
	myBuffer.pushFront(120);
	std::cout << myBuffer << std::endl;

	std::cout << "Push back two numbers" << std::endl;
	myBuffer.pushBack(8);
	myBuffer.pushBack(7.15);
	std::cout << myBuffer << std::endl;

	std::cout << "Show all elements using []" << std::endl;
	for (int i = 0; i < myBuffer.getSize(); i++)
	{
		std::cout << myBuffer[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Iterate 10 times through buffer" << std::endl;
	auto it = myBuffer.begin();
	for (int i = 0; i < 10; i++)
	{
		std::cout << *it << " ";
		it = std::next(it);
	}
	std::cout << std::endl;

	std::cout << "Change capacity to 10" << std::endl;
	myBuffer.resize(10);

	std::cout << "Push back two zeros" << std::endl;
	myBuffer.pushBack(0);
	myBuffer.pushBack(0);
	std::cout << myBuffer << std::endl;

	std::cout << "Sort by stl algorithm" << std::endl;
	std::cout << myBuffer << std::endl;
	std::sort(myBuffer.ubegin(), myBuffer.uend());
	std::cout << myBuffer << std::endl;

	std::cout << "Is any element less than zero?" << std::endl;
	std::cout << std::any_of(myBuffer.ubegin(), myBuffer.uend(), [](double el)-> bool { return el < 0; });
}

int main()
{
	std::cout << "Starting tests" << std::endl;
	TestOnDouble();
	std::cout << "Test passed" << std::endl;
	ShowOnDouble();
}
