#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string Name;
public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	~DiamondTrap();
	DiamondTrap (const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);

	void attack(const std::string& target);
	void whoAmI();
};

#endif