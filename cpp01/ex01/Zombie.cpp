#include "Zombie.hpp"

Zombie::Zombie()
{
	// this->name = name;
}

Zombie::~Zombie()
{
	static int i = 1;
	std::cout << name << i++ << " decomposed." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	static int i = 1;
	std::cout << name << i++ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
