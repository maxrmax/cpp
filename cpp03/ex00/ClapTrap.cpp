#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->Name = "Bob";
	this->atk = 0;
	this->EP = 10;
	this->HP = 10;
	std::cout << "ClapTrap " << Name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	this->atk = 0;
	this->EP = 10;
	this->HP = 10;
	std::cout << "ClapTrap " << Name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " deconstructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	Name = other.Name;
	atk = other.atk;
	EP = other.EP;
	HP = other.HP;
	std::cout << "ClapTrap " << Name << " copy constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	this->Name = other.Name;
	this->HP = other.HP;
	this->EP = other.EP;
	this->atk = other.atk;
	std::cout << "ClapTrap " << this->Name << " assignment constructed" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EP == 0)
	{
		std::cout << "ClapTrap " << this->Name << " has not enough energy." << std::endl;
		return;
	}
	else if (this->HP == 0)
	{
		std::cout << "ClapTrap " << this->Name << " has not enough life." << std::endl;
		return;
	}
	this->EP = this->EP - 1;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->atk << " point(s) of damage!" 
	<< " EP left: " << this->EP << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP == 0)
		return;
	if (amount > this->HP)
		this->HP = 0;
	else
		this->HP = this->HP - amount;
	std::cout << "ClapTrap " << this->Name << " has taken " << amount << " point(s) of damage!" 
	<< " HP: " << this->HP << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP == 0 || this->HP == 0)
		return;
	this->EP = this->EP - 1;
	this->HP = this->HP + amount;
	std::cout << "ClapTrap " << this->Name << " has repaired " << amount << " point(s) of damage!"
	<< " HP: " << this->HP << " EP: " << this->EP << std::endl;
}
