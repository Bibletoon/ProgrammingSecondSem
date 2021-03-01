#include "Polynomial.h"

#include <iostream>
#include <string>
#include <vector>

int Polynomial::GetVariablesCount() const
{
	return _variablesCount;
}

Polynomial::Polynomial() : Polynomial(1,new float[1]{0})
{
}

Polynomial::Polynomial(int variablesCount, float* coefficients, bool fromHeighest)
{
	_variablesCount = variablesCount;
	_coefficients = new float[_variablesCount];
	if (fromHeighest)
	{
		for (int i = _variablesCount - 1; i >= 0; i--)
		{
			_coefficients[i] = coefficients[_variablesCount - i - 1];
		}
	} else
	{
		for (int i = 0; i<_variablesCount;i++)
		{
			_coefficients[i] = coefficients[i];
		}
	}
	
}

Polynomial::~Polynomial()
{
	delete[] _coefficients;
}

Polynomial& Polynomial::operator=(const Polynomial& polynomial)
{
	_variablesCount = polynomial._variablesCount;
	_coefficients = new float[_variablesCount];
	for (int i=0; i<_variablesCount; i++)
	{
		_coefficients[i] = polynomial._coefficients[i];
	}
	return *this;
}

bool Polynomial::operator==(const Polynomial& polynomial) const
{
	if (_variablesCount != polynomial._variablesCount) return false;
	for (int i=0; i<_variablesCount; i++)
	{
		if (_coefficients[i] != _coefficients[i]) return false;
	}
	return true;
}

bool Polynomial::operator!=(const Polynomial& polynomial) const
{
	if (_variablesCount != polynomial._variablesCount) return true;
	for (int i = 0; i < _variablesCount; i++)
	{
		if (_coefficients[i] != _coefficients[i]) return true;
	}
	return false;
}

Polynomial Polynomial::operator-()
{
	float* newCoefficients = new float[_variablesCount];
	for (int i=0;i<_variablesCount; i++)
	{
		newCoefficients[i] = _coefficients[i] * (-1);
	}
	return Polynomial(_variablesCount, newCoefficients, false);
}

Polynomial Polynomial::operator-(const Polynomial& polynomial)
{
	int variablesCount = std::max(_variablesCount, polynomial._variablesCount);
	float* newCoeficients = new float[variablesCount];
	for (int i=0; i<variablesCount;i++)
	{
		float coefficient = 0;
		if (i<_variablesCount)
		{
			coefficient += _coefficients[i];
		}
		if (i<polynomial._variablesCount)
		{
			coefficient -= polynomial._coefficients[i];
		}
		newCoeficients[i] = coefficient;
	}
	return Polynomial(variablesCount, newCoeficients, false);
}

Polynomial Polynomial::operator+(const Polynomial& polynomial)
{
	int variablesCount = std::max(_variablesCount, polynomial._variablesCount);
	float* newCoeficients = new float[variablesCount];
	for (int i = 0; i < variablesCount; i++)
	{
		float coefficient = 0;
		if (i < _variablesCount)
		{
			coefficient += _coefficients[i];
		}
		if (i < polynomial._variablesCount)
		{
			coefficient += polynomial._coefficients[i];
		}
		newCoeficients[i] = coefficient;
	}
	return Polynomial(variablesCount, newCoeficients, false);
}

Polynomial& Polynomial::operator+=(const Polynomial& polynomial)
{
	int variablesCount = std::max(_variablesCount, polynomial._variablesCount);
	float* newCoeficients = new float[variablesCount];
	for (int i = 0; i < variablesCount; i++)
	{
		float coefficient = 0;
		if (i < _variablesCount)
		{
			coefficient += _coefficients[i];
		}
		if (i < polynomial._variablesCount)
		{
			coefficient += polynomial._coefficients[i];
		}
		newCoeficients[i] = coefficient;
	}
	_variablesCount = variablesCount;
	delete[] _coefficients;
	_coefficients = newCoeficients;
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& polynomial)
{
	int variablesCount = std::max(_variablesCount, polynomial._variablesCount);
	float* newCoeficients = new float[variablesCount];
	for (int i = 0; i < variablesCount; i++)
	{
		float coefficient = 0;
		if (i < _variablesCount)
		{
			coefficient += _coefficients[i];
		}
		if (i < polynomial._variablesCount)
		{
			coefficient -= polynomial._coefficients[i];
		}
		newCoeficients[i] = coefficient;
	}
	_variablesCount = variablesCount;
	delete[] _coefficients;
	_coefficients = newCoeficients;
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& polynomial) const
{
	int variablesCount = _variablesCount + polynomial._variablesCount - 1;
	float* newCoefficients = new float[variablesCount];
	for (int i = 0; i < variablesCount; i++) { newCoefficients[i] = 0; }
	for (int i=0;i<_variablesCount;i++)
	{
		for (int j=0;j<polynomial._variablesCount;j++)
		{
			newCoefficients[i + j] += _coefficients[i] * polynomial._coefficients[j];
		}
	}
	return Polynomial(variablesCount, newCoefficients);
}

Polynomial Polynomial::operator*(float coefficient) const
{
	if (coefficient == 0)
	{
		return Polynomial();
	}
	float* newCoefficient = new float[_variablesCount];
	for (int i=0; i<_variablesCount;i++)
	{
		newCoefficient[i] = _coefficients[i] * coefficient;
	}
	return Polynomial(_variablesCount, newCoefficient, false);
}

Polynomial Polynomial::operator/(float coefficient) const
{
	if (coefficient == 0)
	{
		throw std::logic_error("Zero division");
	}
	float* newCoefficient = new float[_variablesCount];
	for (int i = 0; i < _variablesCount; i++)
	{
		newCoefficient[i] = _coefficients[i] / coefficient;
	}
	return Polynomial(_variablesCount, newCoefficient, false);
}

Polynomial& Polynomial::operator*=(const Polynomial& polynomial)
{
	int variablesCount = _variablesCount + polynomial._variablesCount;
	float* newCoefficients = new float[variablesCount];
	for (int i = 0; i < variablesCount; i++) { newCoefficients[i] = 0; }
	for (int i = 0; i < _variablesCount; i++)
	{
		for (int j = 0; j < polynomial._variablesCount; j++)
		{
			newCoefficients[i + j] += _coefficients[i] * polynomial._coefficients[j];
		}
	}
	delete[] _coefficients;
	_variablesCount = variablesCount;
	_coefficients = newCoefficients;
	return *this;
}

Polynomial& Polynomial::operator*=(float coefficient)
{
	if (coefficient == 0)
	{
		delete[] _coefficients;
		_coefficients = new float[1];
		_variablesCount = 1;
		return *this;
	}
	for (int i = 0; i < _variablesCount; i++)
	{
		_coefficients[i] = _coefficients[i] * coefficient;
	}
	return *this;
}

Polynomial& Polynomial::operator/=(float coefficient)
{
	if (coefficient == 0)
	{
		throw std::logic_error("Zero division");
	}
	for (int i = 0; i < _variablesCount; i++)
	{
		_coefficients[i] = _coefficients[i] / coefficient;
	}
	return *this;
}

float Polynomial::operator[](int index) const
{
	if (index<0 || index>=_variablesCount)
	{
		throw std::out_of_range("Index out of range");
	}
	return _coefficients[index];
}


std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial)
{
	bool firstIsOut = false;
	for (int i= polynomial.GetVariablesCount()-1;i>=0;i--)
	{
		if (polynomial[i] == 0 && polynomial.GetVariablesCount()) continue;
		if (polynomial[i] > 0 && firstIsOut)
		{
			out << "+";
		}
		firstIsOut = true;
		if (i==0 || (polynomial[i]!=1 && polynomial[i]!=-1))
		{
			out << polynomial[i];
		} else if (polynomial[i]==-1)
		{
			out << "-";
		}
		if (i == 1)
		{
			out << "x";
		}
		else if (i > 1)
		{
			if (abs(polynomial[i])==1)
			{
				out << "x^" << i;
			} else
			{
				out << "(x^" << i << ")";
			}
		}
	}
	if (!firstIsOut) out << "0";
	return out;
}

std::istream& operator>>(std::istream& in, Polynomial& polynomial)
{
	std::vector<float> coefficients = std::vector<float>();
	float number;
	int i = 0;
	while (in.peek() != '\n')
	{
		in >> number;
		i++;
		coefficients.push_back(number);
	}
	float* newCoefficients = new float[i];
	for (int j = 0; j<i;j++)
	{
		newCoefficients[j] = coefficients[j];
	}
	coefficients.clear();
	coefficients.shrink_to_fit();
	polynomial = Polynomial(i, newCoefficients);
	return in;
}
