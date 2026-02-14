#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	// how to call name and weapon
	std::cout << name << " attacks with their ";
	if (weapon == NULL)
		std::cout << "bare hands" << std::endl; 
	else
		std::cout << weapon->getType() << std::endl; 
}