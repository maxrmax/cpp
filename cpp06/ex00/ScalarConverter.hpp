#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter const &other) = delete;
		ScalarConverter	&operator=(ScalarConverter const &other) = delete;
		~ScalarConverter() = delete;

		static void		convert(std::string const &s);
};

#endif


