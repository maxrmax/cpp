#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d1("GOLDENWIND");
	DiamondTrap d2;
	DiamondTrap d3(d1);
	DiamondTrap d4("DIAMONDHANDS");

	d2 = d4;

	d1.attack("1111");
	d2.attack("2222");
	d1.guardGate();
	d1.highFivesGuys();
	d1.whoAmI();

	d2.takeDamage(50);
	d2.beRepaired(20);
	d2.guardGate();
	d2.whoAmI();

	d3.takeDamage(100);
	d3.attack("target2");
	d3.whoAmI();

	d4.whoAmI();
}