#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	// -- required 50/50 array, deleted as Animals --
	// expected: 5x (Animal + Brain + Dog) constructors, 5x (Animal + Brain + Cat) constructors
	std::cout << "=== 50/50 Animal array ===" << std::endl;
	const Animal *animals[10];
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << " ";
		animals[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << i + 1 << " ";
		animals[i] = new Cat();
	}

	// expected: 5x WanWan!, 5x Nyaa~
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	// expected: 5x (Brain + Dog + Animal) destructors, 5x (Brain + Cat + Animal) destructors
	// deleted as Animal* -> virtual destructor ensures correct order
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << " ";
		delete animals[i];
	}

	std::cout << std::endl;

	// -- deep copy test --
	// Brain copy constructor must fire -> proving deep copy, not shallow
	std::cout << "=== Deep copy test ===" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	std::cout << "dog1 brain address: " << &dog1 << std::endl;
	std::cout << "dog2 brain address: " << &dog2 << std::endl;
	dog2.makeSound(); // expected: WanWan!

	std::cout << std::endl;

	// -- deep assignment test --
	// expected: 2x (Animal + Brain + Cat) constructors
	// then Animal + Brain + Cat assignment operators -> proving deep copy on assignment
	std::cout << "=== Deep assignment test ===" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1; // copy assignment
	std::cout << "cat1 brain address: " << &cat1 << std::endl;
	std::cout << "cat2 brain address: " << &cat2 << std::endl;
	cat2.makeSound(); // expected: Nyaa~

	std::cout << std::endl;

	// -- stack allocated --
	// expected: Animal + Brain + Dog, Animal + Brain + Cat constructors
	std::cout << "=== Stack test ===" << std::endl;
	Dog stackDog;
	Cat stackCat;
	stackDog.makeSound(); // expected: WanWan!
	stackCat.makeSound(); // expected: Nyaa~

	// LIFO, last in, first out
	// deconstruction order from bottom to top:
	// start from stackCat up to dog1

	return 0;
}
