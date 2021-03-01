#pragma once
#include <iterator>
template <class T>
class SimpleIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
	~SimpleIterator() = default;
	SimpleIterator() : _pointer(nullptr) {}
	SimpleIterator(T* pointer) : _pointer(pointer) {}
	SimpleIterator(const SimpleIterator& iterator) : _pointer(iterator._pointer) {}

	SimpleIterator& operator+=(difference_type rhs) { _pointer += rhs; return *this; }
	SimpleIterator& operator-=(difference_type rhs) { _pointer -= rhs; return *this; }
	T& operator*() const { return *_pointer; }
	T* operator->() const { return _pointer; }
	T& operator[](difference_type index) const { return _pointer[index]; }

	SimpleIterator& operator++() { ++_pointer; return *this; }
	SimpleIterator& operator--() { --_pointer; return *this; }
	SimpleIterator operator++(int) { SimpleIterator temp(*this); ++_pointer; return temp; }
	SimpleIterator operator--(int) { SimpleIterator temp(*this); --_pointer; return temp; }

	difference_type operator-(const SimpleIterator& iterator) const { return _pointer - iterator._pointer; }
	SimpleIterator operator+(int rhs) const { return SimpleIterator(_pointer + rhs); }
	SimpleIterator operator-(int rhs) const { return SimpleIterator(_pointer - rhs); }
	friend SimpleIterator operator+(difference_type lhs, const SimpleIterator& rhs) { return SimpleIterator(lhs + rhs._poiter); }
	friend SimpleIterator operator-(difference_type lhs, const SimpleIterator& rhs) { return SimpleIterator(lhs - rhs._pointer); }

	bool operator==(const SimpleIterator& rhs) const { return _pointer == rhs._pointer; }
	bool operator!=(const SimpleIterator& rhs) const { return _pointer != rhs._pointer; }
	bool operator>(const SimpleIterator& rhs) const { return _pointer > rhs._pointer; }
	bool operator<(const SimpleIterator& rhs) const { return _pointer < rhs._pointer; }
	bool operator>=(const SimpleIterator& rhs) const { return _pointer >= rhs._pointer; }
	bool operator<=(const SimpleIterator& rhs) const { return _pointer <= rhs._pointer; }

private:
	T* _pointer;
};