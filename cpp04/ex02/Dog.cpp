#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	this->type = other.type;
	*this->brain = *other.brain;
	std::cout << "Dog assignment constructor" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog deconstructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WanWan!" << std::endl;
}