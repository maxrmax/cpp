#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") 
{
	std::cout << "PresidentialPardonForm Default constructor" << std::endl;  
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;   
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
} 

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
	std::cout << "PresidentialPardonForm assignment operator" << std::endl;
	if (this != &other)
		_target = other._target;  
	return(*this);
} 
  
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor." << std::endl;   
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm:: FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
} 