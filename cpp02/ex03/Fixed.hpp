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
	~Fixed();

	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

/*
 *	fixed-point number value:
 *	42.75 would be saved as 10944 in value
 *	42.75 x 2^8 = 42.75 x 256 = 10944
 *
 *	fractBits is to tell 8 bits are reserved
 *	for the fractional (decimal) part of the number
 *
 */