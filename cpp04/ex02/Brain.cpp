#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain assignment constructor" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor" << std::endl;
}
