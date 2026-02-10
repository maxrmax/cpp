#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	// this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " decomposed." << std::endl;
}


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// first implement a zombie class
// -> class Zombie in .hpp
// add a member function void announce (void); to the class
// Zombies announce themselves as follow:
// <name>: BraiiiiiiinnnzzzZ...

// then implement the following two functions:

// Zombie* newZombie (std::string name);
// creates a zombie, names it, and returns it, so you can use it outside the function scope
// void randomChump (std::string name);
// creates a zombie, names it, and makes it announce itself.

// whats the point of this exercise?
// stack or heap allocation.

// zombies must be destroyed when not needed anymore.
// descrutor must print message of which zombie died

/*

obviously: 
Zombie* zombie -> heap
Zombie zombie -> stack

*/