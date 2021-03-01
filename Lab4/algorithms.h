#pragma once
#include <iterator>


namespace  myAlgorithms
{
	template<class Iterator, class UnaryPredicate>
	bool all_of(const Iterator& first, const Iterator& last, const UnaryPredicate& func)
	{
		for (auto it = first; it != last; it = std::next(it))
		{
			if (!func(*it)) return false;
		}
		return true;
	}

	template<class Iterator, class UnaryPredicate>
	bool any_of(const Iterator& first, const Iterator& last, const UnaryPredicate& func)
	{
		for (auto it = first; it != last; it = std::next(it))
		{
			if (func(*it)) return true;
		}
		return false;
	}

	template<class Iterator, class UnaryPredicate>
	bool none_of(const Iterator& first, const Iterator& last, const UnaryPredicate& func)
	{
		for (auto it = first; it != last; it = std::next(it))
		{
			if (func(*it)) return false;
		}
		return true;
	}

	template<class Iterator, class UnaryPredicate>
	bool one_of(const Iterator& first, const Iterator& last, const UnaryPredicate& func)
	{
		bool was = false;
		for (auto it = first; it != last; it = std::next(it))
		{
			if (func(*it))
			{
				if (was) return false;
				was = true;
			}
		}
		return was;
	}

	template<class Iterator, class Comparator>
	bool is_sorted(const Iterator& first, const Iterator& last, const Comparator& func)
	{
		if (first == last) return true;
		Iterator prev = first;
		for (auto cur = std::next(first); cur != last; cur = std::next(cur))
		{
			if (!func(*prev, *cur)) return false;
			prev = cur;
		}
		return true;
	}

	template<class Iterator, class UnaryPredicate>
	bool is_partitioned(const Iterator& first, const Iterator& last, const UnaryPredicate& func)
	{
		Iterator it = first;
		while (it != last && func(*it))
		{
			it = std::next(it);
		}
		while (it != last)
		{
			if (func(*it)) return false;
			it = std::next(it);
		}
		return true;
	}

	template<class Iterator, class T>
	Iterator find_not(const Iterator& first, const Iterator& last, T element)
	{
		Iterator it;
		for (it = first; it != last; it = std::next(it))
		{
			if (*it != element) return it;
		}
		return it;
	}

	template<class Iterator, class T>
	Iterator find_backward(const Iterator& first, const Iterator& last, T element)
	{
		Iterator it = std::prev(last);

		while (it != first)
		{
			if (*it == element) return it;
			it = std::prev(it);
		}
		if (*it == element) return it;
		return std::prev(it);
	}

	template<class Iterator, class Comparator>
	bool is_palindrome(const Iterator& first, const Iterator& last, const Comparator& func)
	{
		if (first == last) return true;
		auto rightIt = std::prev(last);
		auto leftIt = first;
		while (leftIt!=last)
		{
			if (!func(*leftIt, *rightIt)) return false;
			leftIt = std::next(leftIt);
			rightIt = std::prev(rightIt);
		}
		return true;
	}
}