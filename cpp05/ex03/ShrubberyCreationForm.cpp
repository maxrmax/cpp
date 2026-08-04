#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignment operator" << std::endl;
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "       ,.,\n";
	file << "      MMMM_    ,..,\n";
	file << "        \"_ \"__\"MMMMM          ,...,,\n";
	file << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM\n";
	file << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n";
	file << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n";
	file << "        ,., _\"__ \\__./ .\"\n";
	file << "       MMMMM_\"  \"_    ./\n";
	file << "        ''''      (    )\n";
	file << " ._______________.-'____\"---._.\n";
	file << "  \\                          /\n";
	file << "   \\________________________/\n";
	file << "   (_)                    (_)\n";
}
