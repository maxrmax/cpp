#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	{
		AForm* rrf;
		Bureaucrat B("B", 45);
		rrf = someRandomIntern.makeForm("robotomy request", "Your Brain");
		std::cout << std::endl;
		rrf->beSigned(B);
		B.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	{
		AForm* rrf;
		Bureaucrat B("B", 4);
		rrf = someRandomIntern.makeForm("presidential pardon", "Your Mom");
		std::cout << std::endl;
		rrf->beSigned(B);
		B.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	{
		AForm* rrf;
		Bureaucrat B("B", 137);
		rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
		std::cout << std::endl;
		rrf->beSigned(B);
		B.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("enlargement", "genital"); // not valid
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------------------------------" << std::endl;

	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", ""); // no error, form gets created anyway
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}