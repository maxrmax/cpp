#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	this->type = other.type;
	*this->brain = *other.brain;
	std::cout << "Cat assignment constructor" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat deconstructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Nyaa~" << std::endl;
}