#pragma once

#include <iostream>

class Fixed
{
private:
	// stores the fixed-point number value
	int value;
	static const int fractBits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits (void) const;
	void setRawBits (int const raw);
};

/*
 *	fixed-point number value:
 *	42.75 would be saved as 10944 in value
 *	42.75 x 2^8 = 42.75 x 256 = 10944
 *
 *	fractBits is to tell 8 bits are reserved
 *	for the fractional (decimal) part of the number
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/