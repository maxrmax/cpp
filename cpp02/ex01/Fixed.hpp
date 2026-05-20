#pragma once

#include <iostream>
#include <cmath>
// only allowed is roundf (roundfloat)

class Fixed
{
private:
	// stores the fixed-point number value
	int value;
	static const int fractBits = 8;
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits (void) const;
	void setRawBits (int const raw);

	float toFloat (void) const;
	int toInt (void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

/*
 *	fixed-point number value:
 *	42.75 would be saved as 10944 in value
 *	42.75 x 2^8 = 42.75 x 256 = 10944
 *
 *	fractBits is to tell 8 bits are reserved
 *	for the fractional (decimal) part of the number
 *
*/