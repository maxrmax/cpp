#include "contacts.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

int Contact::set_first_name(std::string first_name)
{
	if (first_name.empty() || !std::all_of(first_name.begin(), first_name.end(), ::isalpha))
		return (1);
	this->first_name = first_name;
	return (0);
}

std::string Contact::get_first_name()
{
	return this->first_name;
}

int Contact::set_last_name(std::string last_name)
{
	if (last_name.empty() || !std::all_of(last_name.begin(), last_name.end(), ::isalpha))
		return (1);
	this->last_name = last_name;
	return (0);
}

std::string Contact::get_last_name()
{
	return this->last_name;
}

int Contact::set_nickname(std::string nickname)
{
	if (nickname.empty() || !std::all_of(nickname.begin(), nickname.end(), ::isalpha))
		return (1);
	this->nickname = nickname;
	return (0);
}

std::string Contact::get_nickname()
{
	return this->nickname;
}

int Contact::set_number(std::string number)
{
	if (number.empty() || !std::all_of(number.begin(), number.end(), ::isdigit))
		return (1);
	this->number = number;
	return (0);
}

std::string Contact::get_number()
{
	return this->number;
}

int Contact::set_secret(std::string secret)
{
	if (secret.empty() || !std::all_of(secret.begin(), secret.end(), ::isascii))
		return (std::cout << "Invalid Input" << std::endl, 1);
	this->secret = secret;
	return (0);
}

std::string Contact::get_secret()
{
	return this->secret;
}

void Contact::print_contact()
{
	std::cout << "-------------------------------------------" << "\n"
			  << "Contact Information:" << "\n"
			  << "First name:\t\t" << first_name << "\n"
			  << "Last name:\t\t" << last_name << "\n"
			  << "Nickname:\t\t" << nickname << "\n"
			  << "Number:\t\t\t" << number << "\n"
			  << "Darkest Secret:\t\t" << secret << "\n"
			  << "-------------------------------------------" << std::endl;
}