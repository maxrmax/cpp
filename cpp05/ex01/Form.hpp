#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
//#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form();
		Form(const Form& other);
		Form(std::string name, int gradeSign, int gradeExec);
		Form& operator=(const Form& other);
		~Form();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeExec() const;
		int					getGradeSign() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		
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

std::ostream&	operator<<(std::ostream &output, Form const &other);

#endif