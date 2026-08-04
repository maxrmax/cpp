#include "AForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator" << std::endl;
	(void)other;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}

AForm* Intern::createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string makeforms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*internforms[3])(std::string) = {&Intern::createRobotomy, &Intern::createPardon, &Intern::createShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (form == makeforms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*internforms[i])(target));
		}
	}

	throw NotValidFormException();
}

const char* Intern::NotValidFormException::what() const throw()
{
	return("Requested Form not valid");
}