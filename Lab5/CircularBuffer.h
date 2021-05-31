#pragma once
#include "CircularIterator.h"
#include "SimpleIterator.h"

template <class T>
class CircularBuffer
{
public:
	CircularBuffer() : _data(nullptr), _capacity(0)
	{
	}

	explicit CircularBuffer(size_t capacity) : _capacity(capacity)
	{
		_data = new T[capacity];
	}

	CircularBuffer(const CircularBuffer& buffer) : _data(buffer._data), _size(buffer._size), _capacity(buffer._capacity)
	{
	}

	CircularBuffer(const std::initializer_list<T>& initList)
	{
		_capacity = initList.size();
		_size = 0;
		_data = new T[_capacity];
		int i = 0;
		for (auto iterator = initList.begin(); iterator != initList.end(); ++iterator)
		{
			_data[_size] = *iterator;
			_size++;
		}
	}

	~CircularBuffer()
	{
		delete[] _data;
	}

	CircularBuffer& operator=(const CircularBuffer& buffer)
	{
		_capacity = buffer._capacity;
		_size = buffer._size;
		T* newCollection = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			newCollection[i] = buffer._data[i];
		}
		_data = newCollection;
		return *this;
	}

	CircularBuffer& operator=(const std::initializer_list<T>& initList)
	{
		_capacity = initList.size();
		_size = 0;
		delete[] _data;
		_data = new T[_capacity];
		for (auto iterator = initList.begin(); iterator != initList.end(); ++iterator)
		{
			pushBack(*iterator);
		}
		return *this;
	}

	T operator[](int index) const
	{
		return _data[index % _capacity];
	}

	CircularIterator<T> begin() const
	{
		return CircularIterator<T>(_data, _data, _data + _size - 1, _capacity);
	}

	SimpleIterator<T> ubegin() const
	{
		return SimpleIterator<T>(_data);
	}

	CircularIterator<T> end() const
	{
		return CircularIterator<T>(_data + _size - 1, _data, _data + _size - 1, _capacity);
	}

	SimpleIterator<T> uend() const
	{
		return SimpleIterator<T>(_data + _size);
	}

	void pushFront(T element)
	{
		for (size_t i = _size - (1 * (_size == _capacity)); i > 0; i--)
		{
			_data[i] = _data[i - 1];
		}
		_data[0] = element;
		if (_size < _capacity)
		{
			_size++;
		}
	}

	void popFront()
	{
		if (_size == 0) return;
		for (size_t i = 0; i < _size - 1; i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}

	void pushBack(T element)
	{
		if (_size < _capacity)
		{
			_data[_size] = element;
			_size++;
		}
		else
		{
			for (size_t i = 0; i < _capacity - 1; i++)
			{
				_data[i] = _data[i + 1];
			}
			_data[_capacity - 1] = element;
		}
	}

	void popBack()
	{
		if (_size != 0) _size--;
	}

	T getFirst() const
	{
		return _data[0];
	}

	T getLast() const
	{
		return _data[_size - 1];
	}

	size_t getSize() const
	{
		return _size;
	}

	void resize(size_t newSize)
	{
		T* newData = new T[newSize];
		for (size_t i = 0; i < std::min(newSize, _size); i++)
		{
			newData[i] = _data[i];
		}
		_capacity = newSize;
		_size = std::min(newSize, _size);
		delete _data;
		_data = newData;
	}

private:
	T* _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};

template <class T>
std::ostream& operator <<(std::ostream& out, const CircularBuffer<T>& buffer)
{
	for (int i = 0; i < buffer.getSize(); i++)
	{
		out << buffer[i] << " ";
	}
	return out;
}
