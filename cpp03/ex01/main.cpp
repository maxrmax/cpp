#include "ScavTrap.hpp"

int main(void)
{
	// ScavTrap tests
	ScavTrap s1("Robby");
	ScavTrap s2;
	ScavTrap s3(s1);
	ScavTrap s4("Delta");

	s4 = s2;

	s1.attack("target1");
	s1.guardGate();

	s2.takeDamage(50);
	s2.beRepaired(20);
	s2.guardGate();

	s3.takeDamage(100);
	s3.attack("target2");
	s3.guardGate();

	return 0;
}