#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
//#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();									// default constructor
		~Bureaucrat();									// destructor
		Bureaucrat(const std::string name, int grade);	// copy constructor
		Bureaucrat(const Bureaucrat& other);			//
		Bureaucrat& operator=(const Bureaucrat& other);	// copy assignment constructor

		// getter
		const std::string	getName() const;
		int					getGrade() const;

		// setter
		void				incGrade();
		void				decGrade();

		void				signForm(Form& form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

