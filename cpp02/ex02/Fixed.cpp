#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

// deconstructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	value = other.getRawBits();
}

// int constructor
Fixed::Fixed(const int number)
{
	std::cout << "int constructor called" << std::endl;
	value = number << fractBits; // Shift left by 8 bits (multiply by 256)
}

// float constructor
Fixed::Fixed(const float number)
{
	std::cout << "float constructor called" << std::endl;
	value = roundf(number * (1 << fractBits)); // Multiply by 256 and round
}

// arithmetic operators
Fixed &Fixed::operator=(const Fixed &other)
{
	this->value = other.value;
	return *this;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.value = this->value + other.value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.value = this->value - other.value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.value = (this->value * other.value) >> fractBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.value = (this->value << fractBits) / other.value;
	return result;
}

// increment/decrement operators
Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->value--;
	return temp;
}

// comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->value != other.value;
}

// min/max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// functions
int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << fractBits); // Divide by 256
}

int Fixed::toInt(void) const
{
	return value >> fractBits; // Shift right by 8 bits (divide by 256)
}



std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat(); // Print the float representation
	return os;			   // Return stream for chaining
}