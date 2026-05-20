#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	// -- required main --
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " type" << std::endl;
	std::cout << i->getType() << " type" << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	// -- wrong classes --
	const WrongAnimal *wa = new WrongAnimal();	//WrongAnimal
	const WrongAnimal *wc = new WrongCat();		// WrongAnimal

	std::cout << wc->getType() << " type" << std::endl;
	wc->makeSound();	// Awoooo~
	wa->makeSound();	// Awoooo~

	delete wc;	// WrongAnimal
	delete wa;	// WrongAnimal

	std::cout << std::endl;

	// -- array of animals --
	std::cout << "=== Array test ===" << std::endl;
	const Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl;

	// -- copy constructor --
	std::cout << "=== Copy test ===" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	dog2.makeSound();

	std::cout << std::endl;

	// -- assignment operator --
	std::cout << "=== Assignment test ===" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	cat2.makeSound();

	std::cout << std::endl;

	// -- stack allocated --
	std::cout << "=== Stack test ===" << std::endl;
	Dog stackDog;
	Cat stackCat;
	stackDog.makeSound();
	stackCat.makeSound();

	return 0;
}
