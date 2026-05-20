#include "FragTrap.hpp"

int main(void)
{
	FragTrap f1("Worms");
	FragTrap f2;
	FragTrap f3(f1);
	FragTrap f4("Srubbles");

	f4 = f2;

	f1.attack("target1");
	f1.highFivesGuys();

	f2.takeDamage(50);
	f2.beRepaired(20);
	f2.highFivesGuys();

	f3.takeDamage(100);
	f3.attack("target2");
	f3.highFivesGuys();


	return 0;
}