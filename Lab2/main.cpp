#include <iostream>

#include <cassert>
#include "Polynomial.h"


void checkPolynomials()
{
	float* coefficientsOne = new float[5]{5, 4, 3, 2, 1};
	float* coefficientsTwo = new float[3]{7, 5, 3};
	Polynomial polynomialOne = Polynomial(5, coefficientsOne);
	Polynomial polynomialTwo = Polynomial(3, coefficientsTwo);

	Polynomial polynomialPlus = polynomialOne + polynomialTwo;
	Polynomial polynomialMinus = polynomialOne - polynomialTwo;

	Polynomial polynomialMult = polynomialOne * 5;
	Polynomial polynomialDet = polynomialTwo / 3;

	assert(polynomialOne[0] == 1 && polynomialOne[2] == 3);

	assert(polynomialPlus[0] == polynomialOne[0] + polynomialTwo[0] && polynomialPlus[0] == 4);
	assert(polynomialMinus[1] == polynomialOne[1] - polynomialTwo[1] && polynomialMinus[1] == -3);


	assert(polynomialOne == polynomialMult / 3);
	assert(polynomialOne != polynomialTwo);
}

int main()
{
	std::cout << "Starting tests" << std::endl;
	checkPolynomials();
	std::cout << "All tests passed" << std::endl;
	float* coefficientsOne = new float[5]{5, 4, 3, 2, 1};
	float* coefficientsTwo = new float[3]{7, 5, 3};
	Polynomial polynomialOne = Polynomial(5, coefficientsOne);
	Polynomial polynomialTwo = Polynomial(3, coefficientsTwo);

	Polynomial polynomialPlus = polynomialOne + polynomialTwo;
	Polynomial polynomialMinus = polynomialOne - polynomialTwo;

	Polynomial polynomialMult = polynomialOne * 5;
	Polynomial polynomialDet = polynomialTwo / 3;

	std::cout << "First polynomial " << polynomialOne << std::endl;

	std::cout << "First polynomial[0] " << polynomialOne[0] << std::endl;
	std::cout << "First polynomial[4] " << polynomialOne[4] << std::endl;

	std::cout << "Second polynomial " << polynomialTwo << std::endl;

	std::cout << "Negative second polynomial " << -polynomialTwo << std::endl;

	std::cout << "Sum of polynomials " << polynomialPlus << std::endl;
	std::cout << "Difference of polynomials " << polynomialMinus << std::endl;

	std::cout << "Composition of polynomials " << polynomialMult << std::endl;
	std::cout << "Quotient of polynomials " << polynomialDet << std::endl;

	std::cout << "Emply polynomial " << Polynomial() << std::endl;

	Polynomial polynomialInput;
	std::cout << "Enter coefficients for new polynomial: ";
	std::cin >> polynomialInput;
	std::cout << "New polynomial: " << polynomialInput;
}
