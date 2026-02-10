#include <string>
#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Memory: " << &brain << std::endl;
	std::cout << "Memory: " << stringPTR << std::endl;
	std::cout << "Memory: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value: " << brain << std::endl;
	std::cout << "Value: " << *stringPTR << std::endl;
	std::cout << "Value: " << stringREF << std::endl;
}

/*
a string variable is stored at some memory
a pointer that stores the address of our variable
-> PTR holds the address of brain
-> *PTR dereferences to get value of brain "HI THIS IS BRAIN"
a reference (or alias) to brain
-> REF is brain, just a different name
-> &REF gives the same address as brain
-> REF, like brain, directly access value "HI THIS IS BRAIN"

PTR stores address of brain
REF is brain

*/