#include <algorithm>
#include <iostream>
#include <vector>
#include "algorithms.h"
#include "../Lab5/CircularBuffer.h"


template<class T>
bool predicate(T arg)
{
	return arg % 2 == 0;
}

template<class T>
bool sortPredicate(T argOne, T argTwo)
{
	return argOne < argTwo;
}

template<class T>
bool palindromePredicate(T argOne, T argTwo)
{
	return argOne == argTwo;
}

template<class T>
bool partitionPredicate(T arg)
{
	return arg % 2;
}
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	int elToFindNot = 1;
	int elToFindBack = 4;

	std::cout << "Collection ";
	for (int i=0;i<v.size();i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Is all satisfy the predicate? " << myAlgorithms::all_of(v.begin(), v.end(), predicate<int>) << std::endl;
	std::cout << "Is any satisfy the predicate? " << myAlgorithms::any_of(v.begin(), v.end(), predicate<int>) << std::endl;
	std::cout << "Is none satisfy the predicate? " << myAlgorithms::none_of(v.begin(), v.end(), predicate<int>) << std::endl;
	std::cout << "Is only one satisfy the predicate? " << myAlgorithms::one_of(v.begin(), v.end(), predicate<int>) << std::endl;
	std::cout << "Is sorted? " << myAlgorithms::is_sorted(v.begin(),v.end(), sortPredicate<int>) << std::endl;
	std::cout << "Is partitioned: " << std::is_partitioned(v.begin(), v.end(), partitionPredicate<int>) << std::endl;
	std::cout << "First that not equal to " << elToFindNot << ": " << *myAlgorithms::find_not(v.begin(), v.end(), elToFindNot) << std::endl;
	std::cout << "Find last " << elToFindBack << ": " << *myAlgorithms::find_backward(v.begin(), v.end(), elToFindBack) << std::endl;
	std::cout << "Is palindrome: " << myAlgorithms::is_palindrome(v.begin(), v.end(), palindromePredicate<int>) << std::endl;
}
