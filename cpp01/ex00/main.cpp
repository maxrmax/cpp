#include "Zombie.hpp"

int main(void)
{
		randomChump("Stack1");
		randomChump("Stack2");
		Zombie* zombie = newZombie("Heap1");
		Zombie* zombie2 = newZombie("Heap2");
		zombie->announce();
		zombie2->announce();
		delete(zombie);
		delete(zombie2);
}
