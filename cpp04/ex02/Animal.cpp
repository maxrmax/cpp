#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal constructor: " << type << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Animal copy constructor: " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	std::cout << "Animal " << this->type << " assignment constructor" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}