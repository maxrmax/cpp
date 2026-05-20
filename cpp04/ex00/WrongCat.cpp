#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor: " << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	this->type = other.type;
	std::cout << "WrongCat " << this->type << " assignment constructor" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Awoooo~" << std::endl;
}