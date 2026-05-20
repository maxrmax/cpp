#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	// -- abstract class test --
	// Animal a;        // <- uncomment to verify it won't compile
	// new Animal();    // <- same, should not compile

	Dog dog;
	Cat cat;
	dog.makeSound();
	cat.makeSound();

	return 0;
}