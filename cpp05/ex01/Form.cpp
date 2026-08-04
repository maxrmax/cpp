#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form():_name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form Default constructor" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form copy constructor" << std::endl;

	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form assignment operator" << std::endl;
	
	if (this != &other)
		_signed = other._signed;
	return(*this);
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

const std::string Form::getName() const
{
	return(_name);
}

bool Form::getSigned() const
{
	return(_signed);
}

int Form::getGradeExec() const
{
	return(_gradeExec);
}

int Form::getGradeSign() const
{
	return(_gradeSign);
}

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

std::ostream&   operator<<(std::ostream &output, Form const &other)
{
	output << "Form " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getGradeSign() << ", grade to execute: " << other.getGradeExec() << std::endl;
	return output;
}