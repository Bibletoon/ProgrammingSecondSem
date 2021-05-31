#pragma once
#include <iterator>

template <class T>
class CircularIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
	~CircularIterator() = default;

	CircularIterator() : _dataBegin(nullptr), _pointer(nullptr), _dataEnd(nullptr), _capacity(0)
	{
	}

	CircularIterator(T* pointer, T* dataBegin, T* dataEnd, size_t capacity) : _dataBegin(dataBegin), _pointer(pointer),
	                                                                          _dataEnd(dataEnd), _capacity(capacity)
	{
	}

	CircularIterator(const CircularIterator& iterator) : _dataBegin(iterator._dataBegin), _pointer(iterator._pointer),
	                                                     _dataEnd(iterator._dataEnd), _capacity(iterator._capacity)
	{
	}

	CircularIterator& operator+=(difference_type rhs)
	{
		_pointer = _dataBegin + ((_pointer - _dataBegin + rhs) % _capacity);
		return *this;
	}

	CircularIterator& operator-=(difference_type rhs)
	{
		_pointer = _dataEnd - ((_dataEnd - _pointer + rhs) % _capacity);
		return *this;
	}

	T& operator*() const { return *_pointer; }
	T* operator->() const { return _pointer; }

	T& operator[](difference_type index) const
	{
		return *(_dataBegin + ((_pointer - _dataBegin + index) % _capacity));
	}

	CircularIterator& operator++()
	{
		if (_pointer == _dataEnd)
		{
			_pointer = _dataBegin;
		}
		else
		{
			++_pointer;
		}
		return *this;
	}

	CircularIterator& operator--()
	{
		if (_pointer == _dataBegin)
		{
			_pointer = _dataEnd;
		}
		else
		{
			--_pointer;
		}
		return *this;
	}

	CircularIterator operator++(int)
	{
		CircularIterator temp(*this);
		if (_pointer == _dataEnd)
		{
			_pointer = _dataBegin;
		}
		else
		{
			++_pointer;
		}
		return temp;
	}

	CircularIterator operator--(int)
	{
		CircularIterator temp(*this);
		if (_pointer == _dataBegin)
		{
			_pointer = _dataEnd;
		}
		else
		{
			--_pointer;
		}
		return temp;
	}

	difference_type operator-(const CircularIterator& iterator) const
	{
		return _pointer - iterator._pointer;
	}

	CircularIterator operator+(int rhs) const
	{
		return CircularIterator(_dataBegin + ((_pointer - _dataBegin + rhs) % _capacity), _dataBegin, _dataEnd,
		                        _capacity);
	}

	CircularIterator operator-(int rhs) const
	{
		return CircularIterator(_dataEnd - ((_dataEnd - _pointer + rhs) % _capacity), _dataBegin, _dataEnd, _capacity);
	}

	bool operator==(const CircularIterator& rhs) const { return _pointer == rhs._pointer; }
	bool operator!=(const CircularIterator& rhs) const { return _pointer != rhs._pointer; }
	bool operator>(const CircularIterator& rhs) const { return _pointer > rhs._pointer; }
	bool operator<(const CircularIterator& rhs) const { return _pointer < rhs._pointer; }
	bool operator>=(const CircularIterator& rhs) const { return _pointer >= rhs._pointer; }
	bool operator<=(const CircularIterator& rhs) const { return _pointer <= rhs._pointer; }

private:
	T* _dataBegin;
	T* _pointer;
	T* _dataEnd;
	size_t _capacity;
};
