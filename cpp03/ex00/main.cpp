#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1("Alice");
	ClapTrap c2;
	ClapTrap c3(c1);
	ClapTrap c4("Bob");

	c4 = c2;

	c1.attack("target1");

	c1.takeDamage(5);
	c1.takeDamage(3);

	c1.beRepaired(4);

	// Test energy depletion (10 EP, each action costs 1)
	c2.attack("enemy1");
	c2.attack("enemy2");
	c2.attack("enemy3");
	c2.beRepaired(1);
	c2.attack("enemy4");
	c2.attack("enemy5");
	c2.attack("enemy6");
	c2.attack("enemy7");
	c2.attack("enemy8");
	c2.attack("enemy9");
	c2.attack("enemy10"); // Should fail - no energy

	// Test HP depletion
	c3.takeDamage(10);
	c3.attack("target2"); // Should fail - no HP
	c3.beRepaired(5);	  // Should fail - no HP

	// Test damage > HP
	ClapTrap c5("Charlie");
	c5.takeDamage(50);

	return 0;
}