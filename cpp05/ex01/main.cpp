#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat leckeier("Olaf", 1);
		std::cout << leckeier << std::endl;
	
		// name, gradeSign, gradeExec
		Form form("form", 50, 20);
		std::cout << form << std::endl;

		leckeier.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat leckeier("Olaf", 51);
		std::cout << leckeier << std::endl;
	
		Form form("form", 50, 20);
		std::cout << form << std::endl;

		leckeier.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}