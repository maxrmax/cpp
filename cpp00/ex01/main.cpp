#include "phonebook.hpp"

int main(void)
{
	Phonebook phonebook;
	std::string command;
	
	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> command;
		if (command == "EXIT")
			return (0); // break ;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid Input" << std::endl;
	}
	// return (0);
}