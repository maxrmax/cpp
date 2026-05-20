#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string Name;
	unsigned int HP;
	unsigned int EP;
	unsigned int atk;
public:
	ClapTrap();
	ClapTrap(std::string Name);
	~ClapTrap();
	ClapTrap (const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif