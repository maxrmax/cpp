#include "phonebook.hpp"

Phonebook::Phonebook()
{
	contact_count = 0;
	index = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::add_contact()
{
	std::string input;
	Contact* contact = &contacts[index % PHONEBOOK_SIZE];

	std::getline(std::cin, input);
	while (contact->set_first_name(input))
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (contact->set_last_name(input))
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (contact->set_nickname(input))
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
	}
	std::cout << "Enter number: ";
	std::getline(std::cin, input);
	while (contact->set_number(input))
	{
		std::cout << "Enter number: ";
		std::getline(std::cin, input);
	}
	std::cout << "Enter secret: ";
	std::getline(std::cin, input);
	while (contact->set_secret(input))
	{
		std::cout << "Enter secret: ";
		std::getline(std::cin, input);
	}
	index++;
	contact_count++;
}

void print_formatted_name(std::string name, std::string delim)
{
	size_t i;
	if (name.length() > 10)
		std::cout << name.substr(0, 9) << ".";
	else
	{
		std::cout << name;
		for (i = 0; i < 10 - name.length(); i++)
			std::cout << " ";
	}
	std::cout << delim;
}

void Phonebook::search_contact()
{
	std::string input;
	int limit;

	if (contact_count == 0)
	{
		std::cout << "No contacts saved" << std::endl;
		return;
	}
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	if (contact_count > PHONEBOOK_SIZE)
		limit = PHONEBOOK_SIZE;
	else
		limit = contact_count;
	for (int i = 0; i < limit; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		if (contacts[i].get_first_name().length() > 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_first_name().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::right << contacts[i].get_first_name() << "|";
		if (contacts[i].get_last_name().length() > 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_last_name().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::right << contacts[i].get_last_name() << "|";
		if (contacts[i].get_nickname().length() > 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_nickname().substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << std::right << contacts[i].get_nickname() << std::endl;
	}
	std::cout << "Enter index of contact to view: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	int i = input[0] - '0'; 
	while (input.length() != 1 || i > limit - 1 || i < 0)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		i = input[0] - '0';
		if (input.length() != 1 || i > limit - 1 || i < 0)
			std::cout << "Invalid index. Retry: ";
	}
	contacts[i].print_contact();
}