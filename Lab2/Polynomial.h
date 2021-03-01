#pragma once
#include <ostream>

class Polynomial
{
public:
	int GetVariablesCount() const;

	Polynomial();
	Polynomial(int variablesCount, float* coefficients, bool fromHeighest = true);
	~Polynomial();
	Polynomial& operator = (const Polynomial& polynomial);
	
	bool operator == (const Polynomial& polynomial) const;
	bool operator != (const Polynomial& polynomial) const;
	
	Polynomial operator - ();
	Polynomial operator - (const Polynomial& polynomial);
	Polynomial operator + (const Polynomial& polynomial);
	
	Polynomial& operator += (const Polynomial& polynomial);
	Polynomial& operator -= (const Polynomial& polynomial);

	Polynomial operator * (const Polynomial& polynomial) const;
	Polynomial operator * (float coefficient) const;
	Polynomial operator / (float coefficient) const;

	Polynomial& operator *= (const Polynomial& polynomial);
	Polynomial& operator *= (float coefficient);
	Polynomial& operator /= (float coefficient);

	float operator[](int index) const;
private:
	int _variablesCount;
	float* _coefficients;
};

std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);
std::istream& operator>>(std::istream& in, Polynomial& polynomial);