#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->atk = 30;
	this->EP = 100;
	this->HP = 100;
	std::cout << "FragTrap " << Name << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->atk = 30;
	this->EP = 100;
	this->HP = 100;
	std::cout << "FragTrap " << Name << " constructed" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << Name << " deconstructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << Name << " copy constructed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return *this;

	ClapTrap::operator=(other);

	std::cout << "FragTrap " << this->Name << " assignment constructed" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (this->EP == 0)
	{
		std::cout << "FragTrap " << this->Name << " has not enough energy to attack." << std::endl;
		return;
	}
	else if (this->HP == 0)
	{
		std::cout << "FragTrap " << this->Name << " has not enough life to attack." << std::endl;
		return;
	}
	this->EP = this->EP - 1;
	std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->atk << " point(s) of damage!"
			  << " EP left: " << this->EP << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->HP == 0)
	{
		std::cout << "FragTrap " << this->Name << " has not enough life initiate request." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->Name << " requests high-five" << std::endl;
}
