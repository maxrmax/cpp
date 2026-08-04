#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm():_name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "AForm Default constructor" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "AForm copy constructor" << std::endl;

	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignment operator" << std::endl;
	
	if (this != &other)
		_signed = other._signed;
	return(*this);
}

AForm::~AForm()
{
	std::cout << "AForm destroyed." << std::endl;
}

const std::string AForm::getName() const
{
	return(_name);
}

bool AForm::getSigned() const
{
	return(_signed);
}

int AForm::getGradeExec() const
{
	return(_gradeExec);
}

int AForm::getGradeSign() const
{
	return(_gradeSign);
}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

const char* AForm:: FormNotSignedException::what() const throw()
{
	return("Form is not signed");
}

std::ostream&   operator<<(std::ostream &output, AForm const &other)
{
	output << "AForm " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getGradeSign() << ", grade to execute: " << other.getGradeExec() << std::endl;
	return output;
}