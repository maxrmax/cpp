#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->Name = "Cob";
	this->atk = 20;
	this->EP = 50;
	this->HP = 100;
	std::cout << "ScavTrap " << Name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->atk = 20;
	this->EP = 50;
	this->HP = 100;
	std::cout << "ScavTrap " << Name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " deconstructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << Name << " copy constructed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return *this;

	ClapTrap::operator=(other);

	std::cout << "ScavTrap " << this->Name << " assignment constructed" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->EP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has not enough energy to attack." << std::endl;
		return;
	}
	else if (this->HP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has not enough life to attack." << std::endl;
		return;
	}
	this->EP = this->EP - 1;
	std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->atk << " point(s) of damage!"
	 << " EP: " << this->EP << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->HP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has not enough life to guard." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->Name << " is now in Gatekeeper mode" << std::endl;
}
