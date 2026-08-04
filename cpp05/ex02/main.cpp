#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat leckeier("Misaki", 44);
		ShrubberyCreationForm garden("garden");
		leckeier.signForm(garden);
		leckeier.executeForm(garden);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat leckeier("Shoko", 44);
		RobotomyRequestForm robot("Your Brain");
		leckeier.signForm(robot);
		leckeier.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		Bureaucrat leckeier("Yui", 5);
		PresidentialPardonForm pardon("Your Mom");
		leckeier.signForm(pardon);
		leckeier.executeForm(pardon);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}