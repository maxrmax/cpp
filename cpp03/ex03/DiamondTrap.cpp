#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = "Dia";
	this->atk = FragTrap::atk; // Frag::atk = 30
	this->EP = ScavTrap::EP; // Scav::EP = 50
	this->HP = FragTrap::HP; // Frag::HP = 100
	std::cout << "DiamondTrap " << Name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->Name = Name;
	this->atk = 30;
	this->EP = ScavTrap::EP;
	this->HP = FragTrap::HP;
	std::cout << "DiamondTrap " << Name << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << Name << " deconstructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this->Name = other.Name;
	std::cout << "DiamondTrap " << Name << " copy constructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	this->Name = other.Name;
	std::cout << "DiamondTrap " << this->Name << " assignment constructed" << std::endl;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap_name: " << this->Name << " - ClapTrap_name: " << ClapTrap::Name << std::endl;
}
