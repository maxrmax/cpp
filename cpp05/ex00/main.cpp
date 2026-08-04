#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat leckeier("merz", 3);
		std::cout << leckeier << std::endl;

		leckeier.incGrade();
		std::cout << leckeier << std::endl;

		leckeier.decGrade();
		std::cout << leckeier << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Now with errors:" << std::endl;
	try
	{
		Bureaucrat leckeier("merz", 1);
		std::cout << leckeier << std::endl;

		leckeier.incGrade(); // fails, destroys, throws error
		std::cout << leckeier << std::endl;

		leckeier.decGrade();
		std::cout << leckeier << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat leckeier("merz", 151); // fails, throws error
		std::cout << leckeier << std::endl;

		leckeier.incGrade();
		std::cout << leckeier << std::endl;

		leckeier.decGrade();
		std::cout << leckeier << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}