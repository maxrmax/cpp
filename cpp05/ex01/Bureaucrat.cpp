#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_name("Herbert"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignment operator" << std::endl;
	
	if (this != &other)
		_grade = other._grade;
	return(*this);
}

const std::string Bureaucrat::getName() const
{
	return(_name);   
}

int Bureaucrat::getGrade() const
{
	return(_grade);   
}

void Bureaucrat::incGrade()
{
	if (_grade == 1)
		 throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " <<  form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " didn't sign " <<  form.getName() << ", " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

std::ostream&   operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return o;
}