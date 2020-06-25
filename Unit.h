// Unit.hpp

#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include <iostream>
#include <string>

template <class T>
class Unit

{
public:

	bool are_equal(T a, T b)
	{
		return a == b;
	}

	template <class T>
	bool verify(T expected, T got, const std::string& message)
	{
		if (are_equal(expected, got))
		{
			std::cout << message << ": " << "PASSED" << std::endl;
			return true;
		}
		std::cout << message << "Failed! Expected: " << expected << " Got: " << got <<
			" - " << std::endl;
		return false;
	}

};
#endif // UNIT_HPP_INCLUDED